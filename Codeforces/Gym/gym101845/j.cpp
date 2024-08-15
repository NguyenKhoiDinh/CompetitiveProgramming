#include <iostream>
#include <vector>
#include <functional> 
#include <queue> 
const long long inf = 100000000000007LL; 
struct train {
  int to, t, c, f, s; 
};
std::vector <train> adj[505];
long long dist[505], cost[505];
struct node {
  long long dist, cost;
  int u;
  bool operator < (const node &other) const {
    return ((dist > other.dist) || (dist == other.dist && cost > other.cost)); 
  }; 
}; 
std::priority_queue <node> pq; 
int n, m; 

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    dist[i] = inf; 
    cost[i] = inf; 
  } 
  for (int i = 1; i <= m; i++) {
    int u, v, t, c, f, s;
    std::cin >> u >> v >> t >> c >> f >> s; 
    adj[u].push_back((train) {v, t, c, f, s}); 
  }
  dist[1] = 0;
  cost[1] = 0;  
  pq.push((node) {0, 0, 1}); 
  while (pq.empty() == false) {
    node element = pq.top();
    pq.pop(); 
    int u = element.u; 
    if (dist[u] != element.dist) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      train neighbor = adj[u][i]; 
      int tim = element.dist; 
      long long nxt; 
      if (tim < neighbor.s) {
        nxt = neighbor.s;  
      }
      else {
        long long x = (tim - neighbor.s) / neighbor.f + 1; 
        nxt = neighbor.s + x * neighbor.f; 
      }
      int v = neighbor.to; 
      if ((dist[v] > nxt + neighbor.t)) {
        dist[v] = nxt + neighbor.t; 
        cost[v] = cost[u] + neighbor.c;
        pq.push((node) {dist[v], cost[v], v});  
      }
      else if (dist[v] == nxt + neighbor.t && cost[v] > cost[u] + neighbor.c) {
        cost[v] = cost[u] + neighbor.c; 
        pq.push((node) {dist[v], cost[v], v}); 
      }
    }
  }
  std::cout << dist[n] << ' ' << cost[n];
  return 0; 
}