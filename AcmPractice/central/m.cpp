#include <bits/stdc++.h> 

using namespace std;
const long long MOD = 1000000007LL;
long long fact[100005];
int n;
vector <int> adj[100005];
bool visited[100005];
int m;  
int cnt = 0; 
long long ans = 0LL;

void dfs(int u) {
  cnt++;
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v);
    }
  }
}

int main () {
  cin >> n >> m; 
  fact[0] = 1LL; 
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * 1LL * i) % MOD; 
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v; 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  for (int i = 0; i < n; i++) {
    cnt = 0; 
    dfs(i);
    if (cnt > 2) {
      (ans += fact[cnt]) %= MOD; 
    }
  }
  cout << ans; 
  return 0; 
}