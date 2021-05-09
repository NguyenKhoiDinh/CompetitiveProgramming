#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 5005; 
const int inf = 1000000007; 
vector <pair <int, int> > adj[MAX_N];
int n, m; 
int dist[MAX_N];
long long ways[MAX_N];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq; 

int main () {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int type, u, v, w;
    cin >> type >> u >> v >> w; 
    adj[u].push_back(make_pair(v, w));
    if (type == 2) {
      adj[v].push_back(make_pair(u, w));    
    }
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = inf; 
  }
  dist[1] = 0; 
  ways[1] = 1LL;
  pq.push(make_pair(dist[1], 1));
  while (!pq.empty()) {
    pair <int, int> pqTop = pq.top();
    pq.pop();
    int u = pqTop.second; 
    int distance = pqTop.first;
    if (distance != dist[u]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      pair <int, int> neighbor = adj[u][i]; 
      int v = neighbor.first;
      if (dist[v] > dist[u] + neighbor.second) {
        dist[v] = dist[u] + neighbor.second; 
        ways[v] = ways[u]; 
        pq.push(make_pair(dist[v], v));
      }
      else if (dist[v] == dist[u] + neighbor.second) {
        ways[v] += ways[u];
      }
    }
  }
  cout << dist[n] << ' ' << ways[n];
  return 0; 
}