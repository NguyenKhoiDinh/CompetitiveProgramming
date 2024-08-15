#include <iostream>
#include <queue>
#include <utility>
#include <math.h>
#include <functional> 
#include <vector>
const long long inf = 200000000000007LL; 
struct edge {
  int to, weight, c; 
};
std::vector <edge> adj[200005];
int n, m;
long long dist[10005][51][51];  
struct element {
  int u, maxC, minC; 
  bool operator < (const element &other) const {
    return maxC < other.maxC; 
  }
};

void subtask2() {
  std::priority_queue <std::pair <long long, element>, std::vector <std::pair <long long, element> >, std::greater <std::pair <long long, element> > > pq; 
  for (int i = 1; i <= n; i++) {
    for (int maxC = 0; maxC <= 50; maxC++) {
      for (int minC = 0; minC <= 50; minC++) {
        dist[i][maxC][minC] = inf; 
      }
    } 
  }
  dist[1][0][50] = 0LL; 
  pq.push(std::make_pair(0LL, (element) {1, 0, 50}));
  while (pq.empty() == false) {
    std::pair <long long, element> e = pq.top();
    pq.pop(); 
    int u = e.second.u; 
    int maxC = e.second.maxC;
    int minC = e.second.minC; 
    if (e.first != dist[u][maxC][minC]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      edge neighbor = adj[u][i];
      int newMinC = std::min(neighbor.c, minC);
      int newMaxC = std::max(neighbor.c, maxC);
      int v = neighbor.to; 
      if (dist[v][newMaxC][newMinC] > dist[u][maxC][minC] + neighbor.weight) {
        dist[v][newMaxC][newMinC] = dist[u][maxC][minC] + neighbor.weight;
        pq.push(std::make_pair(dist[v][newMaxC][newMinC], (element) {v, newMaxC, newMinC})); 
      }    
    }
  }
  int ans = -1;
  long long minDist = inf;
  for (int minC = 1; minC <= 50; minC++) {
    for (int maxC = minC; maxC <= 50; maxC++) {
      if (minDist > dist[n][maxC][minC]) {
        minDist = dist[n][maxC][minC];
        ans = maxC - minC; 
      }
      else if (minDist == dist[n][maxC][minC]) {
        ans = std::max(ans, maxC - minC); 
      }
    }
  }  
  std::cout << ans;
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w, c;
    std::cin >> u >> v >> w >> c;
    adj[u].push_back((edge) {v, w, c}); 
    adj[v].push_back((edge) {u, w, c}); 
  }
  subtask2(); 
  return 0; 
}