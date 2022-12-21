#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>

const int inf = 4000007; 
std::vector <int> dist;
std::vector <std::vector <int> > rev_dist; 
std::vector <std::vector <std::pair <int, int> > > adj, rev_adj;  
int n, m, numQuery; 
int minSum[2005][2005]; 
struct edge {
  int u, v, weight; 
};
std::vector <edge> listEdges; 

void dijkstra(int start, const std::vector <std::vector <std::pair <int, int> > > adj, std::vector <int> &dist) {
  dist[start] = 0; 
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > pq; 
  pq.push(std::make_pair(0, start)); 
  while (pq.empty() == false) {
    std::pair <int, int> pqTop = pq.top();
    pq.pop();
    if (pqTop.first != dist[pqTop.second]) {
      continue; 
    }
    int u = pqTop.second; 
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, int> neighbor = adj[u][i]; 
      if (dist[neighbor.first] > dist[u] + neighbor.second) {
        dist[neighbor.first] = dist[u] + neighbor.second; 
        pq.push(std::make_pair(dist[neighbor.first], neighbor.first)); 
      }
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m >> numQuery;
  dist.resize(n + 1, inf);
  adj.resize(n + 1);  
  rev_dist.resize(n + 1);
  rev_adj.resize(n + 1);  
  for (int i = 1; i <= n; i++) {
    rev_dist[i].resize(n + 1, inf); 
  }
  for (int i = 1; i <= m; i++) {
    int u, v, weight;
    std::cin >> u >> v >> weight;
    listEdges.push_back((edge) {u, v, weight});
    adj[u].push_back(std::make_pair(v, weight));
    rev_adj[v].push_back(std::make_pair(u, weight));   
  } 
  dijkstra(1, adj, dist);
  for (int i = 2; i <= n; i++) {
    dijkstra(i, rev_adj, rev_dist[i]); 
  }
  for (int i = 2; i <= n; i++) {
    for (int weight = 1; weight <= 2001; weight++) {
      minSum[i][weight] = inf; 
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < (int) listEdges.size(); j++) {
      edge currentEdge = listEdges[j]; 
      int totalDistance = dist[currentEdge.u] + rev_dist[i][currentEdge.v];
      if (totalDistance >= inf) {
        continue; 
      }
      minSum[i][currentEdge.weight] = std::min(minSum[i][currentEdge.weight], totalDistance);  
    }
    for (int weight = 2000; weight >= 1; weight--) {
      minSum[i][weight] = std::min(minSum[i][weight], minSum[i][weight + 1]); 
    }
  }
  for (int query = 1; query <= numQuery; query++) {
    int endVertex, t0; 
    std::cin >> endVertex >> t0; 
    int ans = dist[endVertex]; 
    if (minSum[endVertex][t0 + 1] != inf) {
      ans = std::min(ans, t0 + minSum[endVertex][t0 + 1]);   
    }
    std::cout << ans << std::endl; 
  } 
  return 0; 
}