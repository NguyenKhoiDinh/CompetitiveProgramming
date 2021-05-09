#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 2005; 
vector <int> adj[MAX_N]; 
int n, m;
bool visited[MAX_N];

void dfs(int u) {
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v =adj[u][i];
    if (visited[v] == false) {
      dfs(v);
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v; 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      cnt++;
      dfs(i);
    }
  }
  cout << m - n + cnt;
  return 0; 
}