#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 14; 
long long dp[MAX_N + 2][(1 << MAX_N) + 5]; 
int n, m, numTest; 
vector <int> adj[MAX_N + 2]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;  
    for (int i = 0; i < 2 * n; i++) {
      adj[i].clear(); 
    }
    for (int i = 1; i <= m; i++) {
      char color;
      int u, v;
      cin >> color >> u >> v;
      u--;
      v--; 
      if (color == 'R') {
        adj[u].push_back(v + n);  
      }
      else {
        adj[u + n].push_back(v);
      }
    }
    int half = n; 
    n *= 2; 
    long long ans = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1; 
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int u = 0; u < n; u++) {
        if (dp[u][mask] == 0) {
          continue; 
        }
        if (adj[u].empty() == true) {
          if (u < half) {
            for (int v = half; v < n; v++) {
              if ((mask & (1 << v)) == 0) {
                dp[v][mask | (1 << v)] += dp[u][mask]; 
              }
            }
          }
          else {
            for (int v = 0; v < half; v++) {
              if ((mask & (1 << v)) == 0) {
                dp[v][mask | (1 << v)] += dp[u][mask]; 
              }
            }
          }
        }
        else {
          bool check = true; 
          for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i]; 
            if ((mask & (1 << v)) > 0) {
              check = false;
              break;
            }
          }
          if (check == true) {
            for (int i = 0; i < (int) adj[u].size(); i++) {
              int v = adj[u][i];
              if ((mask & (1 << v)) == 0) {
                dp[v][mask | (1 << v)] += dp[u][mask]; 
              }
            }
          }
        }
      }
    }
    for (int u = half; u < n; u++) {
      if (adj[u].empty() == true) {
        ans += dp[u][(1 << n) - 1]; 
      }
      else {
        bool check = false; 
        for (int i = 0; i < (int) adj[u].size(); i++) {
          if (adj[u][i] == 0) {
            check = true; 
            break; 
          }
        }
        if (check == true) {
          ans += dp[u][(1 << n) - 1]; 
        }
      }
    }    
    cout << ans << endl; 
  }
  return 0; 
}