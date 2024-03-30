#include <iostream>
#include <vector> 
#include <string>
#include <utility> 
#include <math.h> 
int numTest; 
std::vector <int> adj[16]; 
std::pair <std::string, std::string> a[16]; 
int n; 
int f[(1 << 16) + 10][16]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      adj[i].clear(); 
      std::cin >> a[i].first >> a[i].second; 
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        f[mask][i] = -1; 
      }
    }
    for (int i = 0; i < n; i++) {
      f[1 << i][i] = 1; 
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i].first == a[j].first || a[i].second == a[j].second) {
          adj[i].push_back(j);
          adj[j].push_back(i); 
        }
      }
    }  
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if (f[mask][i] == -1) {
          continue; 
        }
        for (int j = 0; j < (int) adj[i].size(); j++) {
          int u = adj[i][j]; 
          if ((mask & (1 << u)) == 0) {
            f[mask | (1 << u)][u] = std::max(f[mask | (1 << u)][u], f[mask][i] + 1); 
          }
        }
      }
    }
    int ans = -1; 
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        ans = std::max(ans, f[mask][i]); 
      }
    }
    std::cout << n - ans << std::endl; 
  }
  return 0; 
}