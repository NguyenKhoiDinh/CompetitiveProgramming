#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <functional>
#include <utility> 
const int inf = 2000000007; 
struct cave {
  int to;
  int atTime;   
};
std::vector <cave> listCave[100005]; 
int V, E, numSuggestions;
std::vector <int> adj[100005];
int dist[100005];  

void dijkstra() {
  for (int i = 1; i <= V; i++) {
    dist[i] = inf; 
  }
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > pq;
  pq.push(std::make_pair(0, 1));
  dist[1] = 0;
  while (!pq.empty()) {
    std::pair <int, int> pqTop = pq.top(); 
    pq.pop(); 
    int distance = pqTop.first; 
    int u = pqTop.second; 
    if (distance != dist[u]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i]; 
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1; 
        pq.push(std::make_pair(dist[v], v)); 
      }
    }
    for (int i = 0; i < (int) listCave[u].size(); i++) {
      cave element = listCave[u][i]; 
      int v = element.to; 
      int nextTime = std::max(element.atTime, dist[u] + 1); 
      if (dist[v] > nextTime) {
        dist[v] = nextTime;
        pq.push(std::make_pair(nextTime, v)); 
      }
    }
  } 
}

int main () {
  std::cin >> V >> E; 
  for (int i = 1; i <= E; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::cin >> numSuggestions; 
  for (int suggestion = 1; suggestion <= numSuggestions; suggestion++) {
    int u, v, atTime;
    std::cin >> atTime >> u >> v; 
    listCave[u].push_back((cave) {v, atTime});
    listCave[v].push_back((cave) {u, atTime}); 
  }
  dijkstra(); 
  if (dist[V] == inf) {
    std::cout << -1; 
  }
  else {
    std::cout << dist[V]; 
  }
  return 0; 
}