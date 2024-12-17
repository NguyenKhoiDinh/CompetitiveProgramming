#include <bits/stdc++.h> 

using namespace std;
int numTest;
int n, root; 
long long a[1000005]; 
vector <int> adj[1000005];
bool dfs(int u, int father, const int &numbTick, vector <int> &f) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (numbTick + a[u] - a[v] >= 0 && (numbTick + a[u] - a[v]) % 2 == 0) {
      f[v] = (numbTick + a[u] - a[v]) / 2; 
    }
    else {
      return false; 
    }
    if (dfs(v, u, numbTick, f) == false) {
      return false;
    } 
  }
  return true; 
}
void dfs_tick(int u, int father, vector <int> &tick, const vector <int> &f) {
  if (father != -1 && (int) adj[u].size() == 1) {
    tick[u] = (f[u] == 0 || f[u] == 1 ? f[u] : -1); 
    return;
  }
  int sum_f = 0; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    } 
    sum_f += f[v];
    dfs_tick(v, u, tick, f);  
  }
  if (f[u] == sum_f) {
    tick[u] = 0; 
  }
  else if (f[u] == sum_f + 1) {
    tick[u] = 1; 
  }
}
void dfs_g_down(int u, int father, vector <long long> &g_down, const vector <int> &f) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    dfs_g_down(v, u, g_down, f);
    g_down[u] += g_down[v] + f[v];  
  }
}
void dfs_g_up(int u, int father, vector <long long> &g_up, const vector <long long> &g_down, const vector <int> &f) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    } 
    g_up[v] = g_up[u] + g_down[u] - g_down[v] - f[v] + f[root] - f[v]; 
    dfs_g_up(v, u, g_up, g_down, f); 
  }
}
bool testAgain(const vector <int> &f) {
  vector <int> tick(n + 1, -1);
  dfs_tick(root, -1, tick, f);
  for (int u = 1; u <= n; u++) {
    if (tick[u] == -1) {    
      return false; 
    }
  }
  vector <long long> g_down(n + 1, 0), g_up(n + 1, 0);
  dfs_g_down(root, -1, g_down, f);
  dfs_g_up(root, -1, g_up, g_down, f);
  for (int u = 1; u <= n; u++) {
    if (a[u] != g_down[u] + g_up[u]) {
      return false;
    }
  }
  cout << "YES" << endl;
  for (int u = 1; u <= n; u++) {
    cout << tick[u] << ' '; 
  }   
  cout << endl; 
  return true; 
}
bool solve(const int &numbTick) {
  vector <int> f(n + 1);
  f[root] = numbTick;
  if (dfs(root, -1, numbTick, f) == false) {
    return false; 
  } 
  return testAgain(f); 
} 
int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      adj[i].clear(); 
    }  
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    root = -1; 
    for (int u = 1; u <= n; u++) {
      if ((int) adj[u].size() == 1) {
        root = u;
        break; 
      }
    }                    
    int child = adj[root][0];
    bool ans = solve(a[root] - a[child]);
    if (ans == false) {
      ans = solve(a[root] - a[child] + 2); 
    }
    if (ans == false) {
      cout << "NO" << endl; 
    }   
  }
  return 0; 
}