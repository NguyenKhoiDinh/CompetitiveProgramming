#include <bits/stdc++.h> 

using namespace std;
const long long inf = 10000000000000007LL; 
int n; 
int parent[5005]; 
int p[5005]; 
long long dist[5005]; 
vector <pair <int, int> > adj[5005];
vector <int> visited; 
bool compare(const pair <int, int> &a, const pair <int, int> &b) {
  return a.second < b.second; 
}
void dfs(int u, int father) {
  parent[u] = father; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    pair <int, int> neighbor = adj[u][i];
    if (neighbor.first == father) {
      continue; 
    }
    dfs(neighbor.first, u); 
  }
}

int main () {
  freopen("migration.inp", "r", stdin);
  freopen("migration.out", "w", stdout);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w; 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
  } 
  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end(), compare); 
  }
  dfs(1, -1); 
  long long ans = 0LL;
  long long total = 0LL; 
  visited.push_back(1);
  for (int step = 1; step <= n; step++) {
    long long minValue = inf;
    int addVertex = -1; 
    for (int i = 0; i < (int) visited.size(); i++) {
      int u = visited[i];
      if (p[u] < (int) adj[u].size()) {
        int v = adj[u][p[u]].first;
        int w = adj[u][p[u]].second;
        if (minValue > dist[u] + w + 2LL * (total - dist[u])) {
          minValue = dist[u] + w + 2LL * (total - dist[u]); 
          addVertex = u; 
        }  
      } 
    }
    cout << ans << endl;
    ans = minValue;
    total += adj[addVertex][p[addVertex]].second; 
    visited.push_back(adj[addVertex][p[addVertex]].first);
    p[addVertex]++;     
  } 
  return 0; 
}