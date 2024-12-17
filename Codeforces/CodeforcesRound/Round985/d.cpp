#include <bits/stdc++.h>

using namespace std;
int n, m;
struct result {
  int a, b, c; 
};
vector <result> ans; 
set <int> adj[100005]; 
bool visited[100005]; 
void dfs(int u) {
  visited[u] = true;
  for (set <int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
    int v = *it; 
    if (visited[v] == false) {
      dfs(v); 
    }
  } 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
    }   
    ans.clear(); 
    for (int j = 1; j <= m; j++) {
      int u, v;
      cin >> u >> v;
      adj[u].insert(v);
      adj[v].insert(u); 
    }
    for (int u = 1; u <= n; u++) {
      while ((int) adj[u].size() > 1) {
        set <int>::iterator it = adj[u].begin(); 
        int v1 = *it; 
        adj[u].erase(it);
        it = adj[u].begin();
        int v2 = *it; 
        adj[u].erase(it);
        ans.push_back((result) {u, v1, v2}); 
        adj[v1].erase(adj[v1].find(u));
        adj[v2].erase(adj[v2].find(u));
        m -= 2; 
        if (adj[v1].find(v2) != adj[v1].end()) {
          m--; 
          adj[v1].erase(adj[v1].find(v2));
          adj[v2].erase(adj[v2].find(v1)); 
        }  
        else {
          m++; 
          adj[v1].insert(v2);
          adj[v2].insert(v1); 
        }
      }
    }
    if (m == 0) {
      cout << (int) ans.size() << endl;
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << endl; 
      }
      continue; 
    }
    for (int u = 1; u <= n; u++) {
      visited[u] = false; 
    }
    vector <int> listVertex; 
    for (int u = 1; u <= n; u++) {
      if (visited[u] == false) {
        listVertex.push_back(u);
        dfs(u); 
      }
    }
    int core = -1;
    for (int i = 0; i < (int) listVertex.size(); i++) {
      int u = listVertex[i];
      if (adj[u].empty() == false) {
        core = u;
        break; 
      }
    }
    for (int i = 0; i < (int) listVertex.size(); i++) {
      int u = listVertex[i];
      if (u != core) {
        set <int>::iterator it = adj[core].begin();
        int v = *it;
        ans.push_back((result) {u, core, v});
        adj[core].erase(adj[core].find(v));
        adj[v].erase(adj[v].find(core));
        adj[u].insert(v);
        adj[v].insert(u);
        adj[core].insert(u);
        adj[u].insert(core);   
      }
    }
    cout << (int) ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << endl;
    }
  }
  return 0; 
}