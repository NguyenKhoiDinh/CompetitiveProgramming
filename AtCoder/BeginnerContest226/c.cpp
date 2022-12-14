#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 200005; 
vector <int> adj[MAX_N];
bool visited[MAX_N];
long long ans = 0LL;
long long Time[MAX_N];  
int n;

void dfs(int u) {
  visited[u] = true;
  ans += Time[u];
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v); 
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> Time[i];
    int cnt;
    cin >> cnt;
    for (int j = 1; j <= cnt; j++) {
      int prev;
      cin >> prev; 
      adj[i].push_back(prev); 
    }
  }
  dfs(n); 
  cout << ans; 
  return 0; 
}