#include <bits/stdc++.h> 

using namespace std;
vector <int> adj[100005]; 
int n, numQueries; 
bool visited[100005]; 
void dfs(int u) {
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v); 
    }
  }
}

int main () {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v; 
    adj[u].push_back(v);  
  }
  cin >> numQueries; 
  for (int query = 1; query <= numQueries; query++) {
    int x, y;
    cin >> x >> y; 
    for (int i = 1; i <= n; i++) {
      visited[i] = false; 
    } 
    dfs(x); 
    cout << (visited[y] == true ? "Yes" : "No") << endl; 
  }
  return 0; 
}