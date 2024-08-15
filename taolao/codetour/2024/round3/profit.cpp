#include <iostream>
#include <bitset> 
#include <map>
#include <unordered_map>
#include <utility>
#include <math.h>
#include <algorithm>
#include <vector>
int n, m; 
std::unordered_map <std::bitset <102>, int> f[102];
int p[105], c[105];
std::bitset <102> adj[105];
std::unordered_map <std::bitset <102>, std::pair <int, std::bitset <102> > > trace[105];    

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> c[i]; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      std::cin >> x;
      if (x == 1) {
        adj[i].set(j, 1);  
      }
    }
  }
  std::bitset <102> B;
  B.reset(); 
  f[0][B] = 0; 
  for (int i = 0; i < n; i++) {
    for (std::unordered_map <std::bitset <102>, int>::iterator it = f[i].begin(); it != f[i].end(); it++) {
      std::bitset <102> key = it->first; 
      int value = it->second; 
      if (f[i + 1].find(key) == f[i + 1].end()) {
        f[i + 1][key] = it->second; 
        trace[i + 1][key] = std::make_pair(i, key);  
      } 
      else {
        if (f[i + 1][key] < it->second) {
          f[i + 1][key] = it->second;
          trace[i + 1][key] = std::make_pair(i, key);
        } 
      }
      int nextValue = it->second;
      for (int b = 1; b <= m; b++) {
        if (key[b] == 0 && adj[i + 1][b] == 1) {
          nextValue -= c[b];
        }
      }
      std::bitset <102> join = key | adj[i + 1]; 
      if (f[i + 1].find(join) == f[i + 1].end()) {
        f[i + 1][join] = nextValue + p[i + 1];
        trace[i + 1][join] = std::make_pair(i, key);  
      } 
      else {
        if (f[i + 1][join] < nextValue + p[i + 1]) {
          f[i + 1][join] = nextValue + p[i + 1];
          trace[i + 1][join] = std::make_pair(i, key);
        } 
      }
    }
  }
  int ans = 0;
  std::bitset <102> key;
  int p = n;  
  for (std::unordered_map <std::bitset <102>, int>::iterator it = f[n].begin(); it != f[n].end(); it++) {
    if (ans < it->second) {
      ans = it->second; 
      key = it->first; 
    }    
  } 
  std::cout << ans << std::endl;
  std::vector <int> ans1, ans2;
  for (int i = 1; i <= m; i++) {
    if (key[i] == 1) {
      ans2.push_back(i); 
    }
  } 
  while (p > 0) {
    std::bitset <102> prevKey = trace[p][key].second; 
    if (f[p - 1][prevKey] != f[p][key]) {
      ans1.push_back(p);
      key = prevKey;     
    }
    p--; 
  }
  std::reverse(ans1.begin(), ans1.end());
  if (ans1.empty() == true) {
    std::cout << 0;
  }
  else {
    for (int i = 0; i < (int) ans1.size(); i++) {
      std::cout << ans1[i] << ' '; 
    }
  }
  std::cout << std::endl;
  if (ans2.empty() == true) {
    std::cout << 0; 
  }
  else {
    for (int i = 0; i < (int) ans2.size(); i++) {
      std::cout << ans2[i] << ' '; 
    }
  }
  return 0; 
}
