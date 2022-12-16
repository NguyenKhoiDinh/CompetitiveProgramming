#include <iostream>
#include <queue>
#include <utility>
#include <functional> 
#include <math.h>
#include <vector>
const int inf = 4000007; 
int dist[2005]; 
int maxWeight[2005]; 
int n, m, numQuery;
std::vector <std::pair <int, int> > adj[2005]; 

void dijkstra(int start) {
  for (int i = 1; i <= n; i++) {
    dist[i] = inf; 
    maxWeight[i] = 0; 
  }
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > pq; 
  dist[start] = 0; 
  pq.push(std::make_pair(0, start)); 
  while (pq.empty() == false) {
    std::pair <int, int> pqTop = pq.top();
    pq.pop(); 
    int distance = pqTop.first;
    int u = pqTop.second; 
    if (dist[u] != distance) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, int> neighbor = adj[u][i];
      int v = neighbor.first;
      int weight = neighbor.second; 
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight; 
        pq.push(std::make_pair(dist[v], v));
        maxWeight[v] = maxWeight[u];
        maxWeight[v] = std::max(maxWeight[v], weight); 
      }
      else if (dist[v] == dist[u] + weight) {
        maxWeight[v] = std::max(maxWeight[v], maxWeight[u]);
        maxWeight[v] = std::max(maxWeight[v], weight); 
      }
    }
  }
}

int main () {
  std::cin >> n >> m >> numQuery;
  for (int i = 1; i <= m; i++) {
    int u, v, weight; 
    std::cin >> u >> v >> weight;
    adj[u].push_back(std::make_pair(v, weight)); 
  }
  dijkstra(1);
  for (int query = 1; query <= numQuery; query++) {
    int vertex, weight; 
    std::cin >> vertex >> weight; 
    std::cout << std::min(dist[vertex], dist[vertex] - (maxWeight[vertex] - weight)) << std::endl; 
  } 
  return 0; 
}