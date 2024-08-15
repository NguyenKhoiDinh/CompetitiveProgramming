#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <queue> 
#include <vector> 
int a[1000005], b[1000005]; 
int c[1000005]; 
int n, m;
long long f[1000005]; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  } 
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> c[i]; 
  }
  std::vector <std::pair <int, int> > v0, v; 
  for (int i = 1; i <= n; i++) {
    v0.push_back(std::make_pair(a[i] - b[i], a[i])); 
  }
  std::sort(v0.begin(), v0.end());   
  v.push_back(v0[0]);
  for (int i = 1; i < (int) v0.size(); i++) {
    if (v0[i].second >= v.back().second) {
      continue; 
    }                                
    v.push_back(v0[i]);     
  }
  long long ans = 0LL;                    
  std::cout << ans;    
  return 0; 
}