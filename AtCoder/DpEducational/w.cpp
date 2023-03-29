#include <iostream>
#include <math.h>
#include <vector> 
const long long inf = -200000000000007LL; 
struct event {
  long long value; 
  int position; 
};
struct node {
  long long lazy;
  long long value; 
};
std::vector <event> listRemoveEvents[200005];
long long ans = 0LL;
node it[4 * 200005];
int n, m;  
long long cost[200005];

void lazyUpdate(int index, const int &L, const int &R) {
  it[index].value += it[index].lazy;
  if (L < R) {
    it[2 * index].lazy += it[index].lazy; 
    it[2 * index + 1].lazy += it[index].lazy; 
  }
  it[index].lazy = 0;
} 

void update(int index, const int &L, const int &R, const int &l, const int &r, const long long &value) {
  lazyUpdate(index, L, R); 
  if (l > R || L > r) {
    return; 
  }
  if (l <= L && R <= r) {
    it[index].lazy += value; 
    lazyUpdate(index, L, R); 
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r, value);
  update(2 * index + 1, mid + 1, R, l, r, value);
  it[index].value = std::max(it[2 * index].value, it[2 * index + 1].value); 
}

long long query(int index, const int &L, const int &R, const int &l, const int &r) {
  lazyUpdate(index, L, R); 
  if (l > R || L > r) {
    return inf; 
  }
  if (l <= L && R <= r) {
    return it[index].value; 
  }
  int mid = (L + R) / 2; 
  long long value1 = query(2 * index, L, mid, l, r);
  long long value2 = query(2 * index + 1, mid + 1, R, l, r);
  return std::max(value1, value2); 
}

int main () {
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    long long value; 
    std::cin >> l >> r >> value;
    cost[l] += value;
    listRemoveEvents[r + 1].push_back((event) {value, l});  
  }
  for (int i = 1; i <= n; i++) {
    update(1, 0, n, 0, i - 1, cost[i]); 
    for (int j = 0; j < (int) listRemoveEvents[i].size(); j++) {
      event e = listRemoveEvents[i][j]; 
      update(1, 0, n, 0, e.position - 1, -e.value); 
    }
    long long currentValue = query(1, 0, n, 0, i - 1); 
    ans = std::max(ans, currentValue); 
    update(1, 0, n, i, i, currentValue); 
  }
  std::cout << ans; 
  return 0; 
}