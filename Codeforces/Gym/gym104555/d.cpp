#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <utility> 
#include <functional>
const int inf = 1000000007;
int F[305][305]; 
int n, m; 
bool should[305][305];
int parent[305][305];  
struct edge {
  int u, v, c; 
};
edge e[100005]; 
int dist[305]; 
std::vector <std::pair <int, int> > adj[305]; 
void dijkstra(int u, int v) {
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > pq; 
  std::vector <int> dist(n + 1, inf); 
  std::vector <bool> visited(n + 1, false); 
  dist[u] = 0; 
  visited[u] = true; 
  pq.push(std::make_pair(0, u)); 
  while (pq.empty() == false) {
    std::pair <int, int> e = pq.top();
    if (e.second == v) {
      printf("%d\n", e.first);
      return;
    }                   
    pq.pop();
    if (parent[e.second][v] != u) {
      pq.push(std::make_pair(e.first + F[e.second][v], v));
      continue; 
    }
    if (e.first != dist[e.second]) {
      continue; 
    } 
    visited[e.second] = true; 
    for (int i = 0; i < (int) adj[e.second].size(); i++) {
      std::pair <int, int> neighbor = adj[e.second][i]; 
      if ((e.second == u && neighbor.first == v) || (e.second == v && neighbor.first == u)) {
        continue; 
      }
      if (visited[neighbor.first] == true) {
        continue; 
      }
      if (dist[neighbor.first] > dist[e.second] + neighbor.second) {
        dist[neighbor.first] = dist[e.second] + neighbor.second; 
        pq.push(std::make_pair(dist[neighbor.first], neighbor.first)); 
      }
    }
  }
  if (dist[v] == inf) {
    printf("-1\n");
  }
  else {
    printf("%d\n", dist[v]); 
  }
}

int main () {
  scanf("%d %d", &n, &m);  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      F[i][j] = inf; 
      parent[i][j] = i; 
    }
    F[i][i] = 0; 
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c); 
    F[e[i].u][e[i].v] = e[i].c;
    F[e[i].v][e[i].u] = e[i].c;   
    adj[e[i].u].push_back(std::make_pair(e[i].v, e[i].c)); 
    adj[e[i].v].push_back(std::make_pair(e[i].u, e[i].c)); 
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (F[i][j] > F[i][k] + F[k][j]) {
          F[i][j] = F[i][k] + F[k][j];
          parent[i][j] = parent[k][j];  
          should[i][j] = true; 
          should[j][i] = true; 
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v; 
    if (should[u][v] == true) {
      printf("%d\n", F[u][v]);  
    }
    else {
      dijkstra(u, v);
    }
  }
  return 0; 
}