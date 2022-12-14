#include <bits/stdc++.h> 

using namespace std;
int in[100005], out[100005];
int n, query;
vector <int> adj[100005];  
vector <int> Left[100005], Right[100005]; 
vector <int> f[100005]; 

void dfs1(int u, int father) {
  out[u] = 0;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs1(v, u); 
  }
  Left[u].push_back(0); 
  Right[u].push_back(0); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    out[u] = max(out[u], out[v] + 1); 
    Left[u].push_back(out[v] + 1);
    Right[u].push_back(out[v] + 1); 
  }
  Left[u].push_back(0);
  Right[u].push_back(0);  
}

void dfs2(int u, int father) {
  int id = 0; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    id++; 
    in[v] = max(Left[u][id - 1], Right[u][id + 1]) + 1; 
    in[v] = max(in[v], in[u] + 1);
    dfs2(v, u); 
  }
}

void dfs3(int u, int father) {
  if (in[u] != -1) {
    f[u].push_back(in[u]);
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    f[u].push_back(out[v] + 1); 
    dfs3(v, u); 
  }  
}

int main () {
  cin >> n >> query;
  for (int i = 1; i <= n; i++) {
    in[i] = out[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1, -1); 
  for (int u = 1; u <= n; u++) {
    int sz = (int) adj[u].size() - 1; 
    for (int i = 1; i <= sz; i++) {
      Left[u][i] = max(Left[u][i - 1], Left[u][i]); 
    }
    for (int i = sz; i >= 1; i--) {
      Right[u][i] = max(Right[u][i], Right[u][i + 1]); 
    }
  }
  dfs2(1, -1); 
  dfs3(1, -1);
  for (int u = 1; u <= n; u++) {
    sort(f[u].begin(), f[u].end());
  }
  for (int i = 1; i <= query; i++) {
    int x, t;
    cin >> x >> t; 
    int lo = 0; 
    int hi = (int) f[x].size() - 1; 
    int numb = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) >> 1; 
      if (f[x][mid] <= t) {
        numb = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    cout << (int) f[x].size() - (numb + 1) << endl; 
  }
  return 0; 
}