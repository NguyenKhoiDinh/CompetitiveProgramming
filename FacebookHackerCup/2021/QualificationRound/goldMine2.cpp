#include <bits/stdc++.h> 

using namespace std;
int numTest; 
const int MAX_N = 55;
const int inf = -1000000007; 
int cost[MAX_N]; 
int n, k;
vector <int> adj[MAX_N]; 
int dp[MAX_N][MAX_N][MAX_N][3][2];
int parent[MAX_N]; 

void dfs(int u, int father) {
  int numChilds = (int) adj[u].size();
  numChilds--;  
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u); 

  }
  if (numChilds == 0) {
    dp[u][numChilds][0][0][0] = 0; 
    dp[u]
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> cost[i]; 
    }
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    for (int i = 1; i < MAX_N; i++) {
      for (int brands = 0; brands < MAX_N; brands++) {
        for (int numDrills = 0; numDrills < MAX_N; numDrills++) {
          for (int state = 0; state < 3; state++) {
            for (int stateChild = 0; stateChild < 2; stateChild++) {
              dp[i][brands][numDrills][state][stateChild] = inf; 
            }
          }
        }
      }
    }
    dp[1][0][0][1][0] = 0; 
    dfs(1, -1);                          
  }
  return 0; 
}