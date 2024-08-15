#include <iostream>
#include <utility>
#include <math.h>
#include <queue>
#include <vector> 
struct element {
  int to, l1, l2; 
};
std::vector <element> adj[200005]; 
int n, m, numTest; 
int t0, t1, t2; 
void dijkstra_custom(int start) {
  std::vector <int> dist(n + 1, -1); 
  std::priority_queue <std::pair <int, int> > pq; 
  dist[n] = t0; 
  pq.push(std::make_pair(dist[n], n));
  while (pq.empty() == false) {
    std::pair <int, int> pqTop = pq.top(); 
    pq.pop(); 
    int distance = pqTop.first; 
    int u = pqTop.second; 
    if (distance != dist[u]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      element neighbor = adj[u][i]; 
      int to = neighbor.to; 
      int l1 = neighbor.l1; 
      int l2 = neighbor.l2; 
      if (dist[to] < dist[u] - l2) {
        dist[to] = dist[u] - l2; 
        pq.push(std::make_pair(dist[to], to)); 
      }
      if (dist[u] - l1 >= t2 || dist[u] <= t1) {
        if (dist[to] < dist[u] - l1) {
          dist[to] = dist[u] - l1; 
          pq.push(std::make_pair(dist[to], to)); 
        }  
      }
      else {
        if (dist[to] < t1 - l1) {
          dist[to] = t1 - l1; 
          pq.push(std::make_pair(dist[to], to)); 
        }
      }
    }
  }
  std::cout << dist[1] << std::endl; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    std::cin >> t0 >> t1 >> t2; 
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
    }
    for (int i = 1; i <= m; i++) {
      int u, v, l1, l2; 
      std::cin >> u >> v >> l1 >> l2; 
      adj[u].push_back((element) {v, l1, l2}); 
      adj[v].push_back((element) {u, l1, l2}); 
    }
    dijkstra_custom(1); 
  }
  return 0; 
}                