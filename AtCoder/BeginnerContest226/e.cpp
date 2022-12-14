#include <bits/stdc++.h> 

using namespace std;
const long long MOD = 998244353LL;
vector <int> adj[200005]; 
int n, m;
bool visited[200005]; 
int countVertex = 0, totalDeg = 0; 

void dfs(int u) {
  visited[u] = true;
  countVertex++;
  totalDeg += (int) adj[u].size(); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v); 
    }
  }
}

int main () {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  long long ans = 1LL;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      countVertex = 0; 
      totalDeg = 0; 
      dfs(i); 
      if (countVertex * 2 == totalDeg) {
        (ans *= 2LL) %= MOD; 
      }
      else {
        ans = 0;
        break; 
      }
    }
  }
  cout << ans; 
  return 0; 
}