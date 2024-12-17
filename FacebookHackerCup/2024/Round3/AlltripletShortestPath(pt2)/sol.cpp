#include <bits/stdc++.h> 

using namespace std; 
bool visited[300005]; 
vector <int> adj[300005]; 
int n; 
bool dfs(int u) {
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == true) {
      continue; 
    }
    if (v < u) {
      return false; 
    }
    return dfs(v); 
  }
  return true;  
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    string type;
    cin >> type; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
      visited[i] = false;
      adj[i].clear(); 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    if (type[0] == 'k') {
      cout << "Lucky" << endl; 
      continue; 
    }
    if (dfs(1) == true) {
      cout << "Lucky" << endl; 
    } 
    else {
      cout << "Wrong" << endl; 
    }
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}