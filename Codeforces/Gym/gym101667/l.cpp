#include <iostream>
#include <vector>
#include <math.h> 
#include <utility> 
#define int long long
const int inf = 100000000000000007LL; 
int members; 
int n[3], m[3], airport[3]; 
int h[3][55]; 
std::vector <std::pair <int, int> > adj[3][55]; 
int f[2][3][55]; 

signed main () {
  std::cin >> members; 
  for (int mem = 0; mem < members; mem++) {
    std::cin >> n[mem] >> m[mem];
    for (int i = 1; i <= n[mem]; i++) {
      std::cin >> h[mem][i]; 
    }
    for (int i = 1; i <= m[mem]; i++) {
      int u, v, weight; 
      std::cin >> u >> v >> weight; 
      adj[mem][u].push_back(std::make_pair(v, weight)); 
    }
    std::cin >> airport[mem];    
  }
  int ans = inf; 
  for (int mem = 0; mem < members; mem++) {
    for (int u = 1; u <= n[mem]; u++) {
      f[0][mem][u] = inf; 
      f[1][mem][u] = inf; 
    }
    f[0][mem][1] = 0; 
  }
  for (int day = 0; day < 200000; day++) {
    int now = day % 2; 
    int nxt = !now; 
    for (int mem = 0; mem < members; mem++) {
      for (int u = 1; u <= n[mem]; u++) {
        f[nxt][mem][u] = inf; 
      }
    }
    for (int mem = 0; mem < members; mem++) {
      for (int u = 1; u <= n[mem]; u++) {
        if (f[now][mem][u] == inf) {
          continue; 
        }
        f[nxt][mem][u] = std::min(f[nxt][mem][u], f[now][mem][u] + h[mem][u]); 
        for (int j = 0; j < (int) adj[mem][u].size(); j++) {
          std::pair <int, int> neighbor = adj[mem][u][j];
          int v = neighbor.first;
          int cost = neighbor.second; 
          f[nxt][mem][v] = std::min(f[nxt][mem][v], f[now][mem][u] + cost);  
        }
      }
    }
    bool ok = true; 
    int total = 0; 
    for (int mem = 0; mem < members; mem++) {
      if (f[now][mem][airport[mem]] == inf) {
        ok = false; 
        break; 
      }
      else {
        total += f[now][mem][airport[mem]]; 
      }
    }
    if (ok == true) {
      ans = std::min(ans, total); 
    }
  }
  std::cout << ans; 
}