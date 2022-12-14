#include <bits/stdc++.h> 

using namespace std;
int numTest; 
const int MAX_N = 55; 
int gold[MAX_N];
int parent[MAX_N];
int dist[MAX_N];
vector <int> adj[MAX_N];
int n;

void dfs(int u, int father) {
  parent[u] = father;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    dist[v] = dist[u] + gold[v];
    dfs(v, u);
  }
}

int findLca(int u, int v) {
  set <int> S;
  while (u != -1) {
    S.insert(u);
    u = parent[u];
  }
  while (true) {
    if (S.find(v) != S.end()) {
      return v;
    }
    v = parent[v];
  }
}

int main () {
  freopen("input2.txt", "r", stdin);
  freopen("output2.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      cin >> gold[i];
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (n == 1) {
      cout << gold[1] << endl;
      continue;
    }
    dfs(1, -1);
    int ans = gold[1]; 
    vector <pair <int, int> > save;
    for (int i = 1; i <= n; i++) {
      if ((int) adj[i].size() == 1 && parent[i] != -1) {
        save.push_back(make_pair(dist[i], i)); 
      }
    }                               
    int maxi = -1;
    if ((int) adj[1].size() == 1) {
      for (int i = 0; i < (int) save.size(); i++) {
        maxi = max(maxi, save[i].first);
      }           
    }
    else {          
      for (int i = 0; i < (int) save.size(); i++) {
        for (int j = i + 1; j < (int) save.size(); j++) {
          int u = save[i].second;
          int v = save[j].second;
          int lca = findLca(u, v);
          if (lca == 1) {
            maxi = max(maxi, dist[u] + dist[v]);  
          }
        }
      }
    }
    ans += maxi;
    cout << ans << endl; 
  }
  return 0; 
}