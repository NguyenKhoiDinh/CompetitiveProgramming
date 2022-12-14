#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <map> 
struct question {
  int l, r, d; 
  int id; 
  bool operator < (const question &other) {
    return d > other.d; 
  }
};
int n, numQuery; 
std::vector <question> listQuery; 
int a[200005];
int f[200005][20];
long long fw[200005];
int firstPosition[200005];                     
long long ans[200005]; 
std::map <int, std::vector <int> > store; 

void update(int index, int value) {
  for (; index <= 200000; index += index & -index) {
    fw[index] += value;   
  }
}

long long get(int index) {
  long long ret = 0LL; 
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int gcdQuery(int l, int r) {
  int j = std::log2(r - l + 1);
  return std::__gcd(f[l][j], f[r - (1 << j) + 1][j]);  
}

void createFirstPosition(int pos, const int &d) {
  int oldValue = firstPosition[pos]; 
  update(pos, -oldValue); 
  firstPosition[pos] = n + 10; 
  int lo = pos; 
  int hi = n;                   
  while (lo <= hi) {                
    int mid = (lo + hi) / 2; 
    if (gcdQuery(pos, mid) <= d) {
      firstPosition[pos] = mid; 
      hi = mid - 1;  
    }
    else {
      lo = mid + 1;  
    }                             
  }
  if (firstPosition[pos] != n + 10) {
    update(pos, firstPosition[pos]);
    store[gcdQuery(pos, firstPosition[pos])].push_back(pos); 
  }
}

int main () {
  std::cin >> n >> numQuery; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    firstPosition[i] = n + 10;
    update(i, firstPosition[i]);  
  }
  for (int query = 1; query <= numQuery; query++) {
    int l, r, d; 
    std::cin >> l >> r >> d; 
    listQuery.push_back((question) {l, r, d, query}); 
  }
  std::sort(listQuery.begin(), listQuery.end()); 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 19; j++) {
      f[i][j] = -1; 
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i][0] = a[i]; 
  }
  for (int j = 1; j <= 19; j++) {
    for (int i = 1; i <= n; i++) {
      int nextPosition = i + (1 << j) - 1; 
      if (nextPosition <= n) {
        f[i][j] = std::__gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]); 
      }  
    }
  }                                     
  for (int i = 1; i <= n; i++) {
    createFirstPosition(i, listQuery[0].d);  
  }
  for (int query = 0; query < (int) listQuery.size(); query++) {
    int l = listQuery[query].l;
    int r = listQuery[query].r; 
    int d = listQuery[query].d;
    int id = listQuery[query].id; 
    std::map <int, std::vector <int> >::iterator it;
    if (store.empty() == false) {
      it = store.end();
      it--;
    } 
    while (true) {
      if (it->first <= d) {
        break;
      }
      if (store.empty() == true) {
        break;
      }
      std::map <int, std::vector <int> >::iterator prev_it = it;
      std::vector <int> &v = it->second;       
      for (int i = 0; i < (int) v.size(); i++) {
        int pos = v[i];
        createFirstPosition(pos, d);                                
      }
      if (it == store.begin()) {
        store.clear();
        break; 
      }
      else {
        it--; 
        store.erase(prev_it);
      }
    } 
    int lo = l;
    int hi = n;
    int pos = -1; 
    while (lo <= hi) {                          
      int mid = (lo + hi) / 2; 
      if (firstPosition[mid] <= r) {
        pos = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    if (pos != -1) {
      ans[id] = 1LL * (pos - l + 1) * (r + 1) - (get(pos) - get(l - 1));
    }
  }
  for (int query = 1; query <= numQuery; query++) {
    std::cout << ans[query] << std::endl; 
  }
  return 0; 
}             