#include <iostream>
#include <string> 
#include <math.h> 
int f[127][127]; 
std::string s, t; 
int m; 

int main () {
  std::cin >> s >> t; 
  for (int i = 1; i <= 126; i++) {
    for (int j = 1; j <= 126; j++) {
      f[i][j] = 150000; 
    }
  }
  for (int i = 1; i <= 126; i++) {
    f[i][i] = 0; 
  }
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    char u, v;
    int cost;
    std::cin >> u >> v >> cost; 
    f[u][v] = std::min(f[u][v], cost); 
  }
  for (int k = 1; k <= 126; k++) {
    for (int u = 1; u <= 126; u++) {
      for (int v = 1; v <= 126; v++) {
        f[u][v] = std::min(f[u][v], f[u][k] + f[k][v]); 
      }
    }
  }
  int ans = 0; 
  for (int i = 0; i < (int) s.size(); i++) {
    if (f[s[i]][t[i]] == 150000) {
      std::cout << "-1";
      return 0; 
    }
    ans += f[s[i]][t[i]]; 
  }
  std::cout << ans;
  return 0; 
}