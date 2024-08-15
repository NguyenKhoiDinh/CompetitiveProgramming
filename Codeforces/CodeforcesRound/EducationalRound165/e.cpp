#include <iostream>
#include <vector>
#include <math.h> 
const int inf = 1000000007; 
int numTest; 
int n;
int a[300005]; 
struct itnode {
  int lazy; 
  int value; 
};
itnode it[4 * 300005]; 
std::vector <int> position[300005];
void lazyUpdate(int index, int L, int R) {
  if (it[index].lazy > 0 && L < R) {
    it[2 * index].lazy += it[index].lazy;
    it[2 * index].value += it[index].lazy;
    it[2 * index + 1].lazy += it[index].lazy;
    it[2 * index + 1].value += it[index].lazy; 
  }
  it[index].lazy = 0; 
}
void update(int index, int L, int R, int l, int r, const int &value) {
  if (l <= L && R <= r) {
    it[index].lazy += value; 
    it[index].value += value;
    lazyUpdate(index, L, R);
    return;  
  }
  lazyUpdate(index, L, R); 
  if (l > R || L > r) {
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r, value);
  update(2 * index + 1, mid + 1, R, l, r, value);
  it[index].value = std::min(it[2 * index].value, it[2 * index + 1].value);  
}  
int get(int index, int L, int R, int l, int r) {
  lazyUpdate(index, L, R); 
  if (l <= L && R <= r) {
    return it[index].value; 
  }
  if (l > R || L > r) {
    return inf; 
  }
  int mid = (L + R) / 2;
  int valueLeft = get(2 * index, L, mid, l, r); 
  int valueRight = get(2 * index + 1, mid + 1, R, l, r); 
  return std::min(valueLeft, valueRight); 
}
int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      position[i].clear(); 
    }
    for (int i = 1; i <= 4 * n; i++) {
      it[i].lazy = 0;
      it[i].value = 0; 
    }
    int lastPosition = 0; 
    int ans = 0;                    
    for (int i = 1; i <= n; i++) {
      position[a[i]].push_back(i);    
      update(1, 1, n, lastPosition + 1, i, 1);
      int sz = (int) position[a[i]].size();
      if (sz >= 2) {
        update(1, 1, n, lastPosition + 1, position[a[i]][sz - 2], -2); 
      }  
      if (sz >= 3) {
        update(1, 1, n, lastPosition + 1, position[a[i]][sz - 3], 1); 
      }
      if (get(1, 1, n, lastPosition + 1, i) == 0) {
        ans++; 
        lastPosition = i; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}