#include <iostream> 
#include <math.h>
#include <queue> 
#include <utility>
#include <vector> 
#include <functional>
const long long inf = 1000000000000007LL; 
int numTest;
long long distM[200005][2], distR[200005][2];
std::vector <std::pair <int, int> > adj[200005];
int n, m, h;
bool horse[200005];  
void dijkstra(int start, long long dist[200005][2]) {
  std::priority_queue <std::pair <long long, std::pair <int, int> >, std::vector <std::pair <long long, std::pair <int, int> > >, std::greater <std::pair <long long, std::pair <int, int> > > > pq;
  dist[start][0] = 0LL;
  pq.push(std::make_pair(0LL, std::make_pair(start, 0)));
  while (pq.empty() == false) {
    std::pair <long long, std::pair <int, int> > pqTop = pq.top();
    pq.pop(); 
    long long distance = pqTop.first; 
    int u = pqTop.second.first; 
    int state = pqTop.second.second;
    if (distance > dist[u][state]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, int> neighbor = adj[u][i];
      int v = neighbor.first;
      int w = neighbor.second;  
      if (state == 0) {
        if (horse[u] == true) {
          if (dist[v][1] > dist[u][0] + w / 2) {
            dist[v][1] = dist[u][0] + w / 2; 
            pq.push(std::make_pair(dist[v][1], std::make_pair(v, 1))); 
          }
        }
        else {
          if (dist[v][0] > dist[u][0] + w) {
            dist[v][0] = dist[u][0] + w; 
            pq.push(std::make_pair(dist[v][0], std::make_pair(v, 0))); 
          }
        }
      }
      else {
        if (dist[v][1] > dist[u][1] + w / 2) {
          dist[v][1] = dist[u][1] + w / 2; 
          pq.push(std::make_pair(dist[v][1], std::make_pair(v, 1))); 
        }                                            
      }
    }
  } 
}

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> h; 
    for (int i = 1; i <= n; i++) {
      horse[i] = false; 
      adj[i].clear(); 
      distM[i][0] = distM[i][1] = inf;
      distR[i][0] = distR[i][1] = inf;
    }
    for (int i = 1; i <= h; i++) {
      int ho;
      std::cin >> ho;
      horse[ho] = true; 
    }
    for (int i = 1; i <= m; i++) {
      int u, v, w; 
      std::cin >> u >> v >> w; 
      adj[u].push_back(std::make_pair(v, w));
      adj[v].push_back(std::make_pair(u, w)); 
    }
    dijkstra(1, distM); 
    dijkstra(n, distR); 
    long long ans = std::min(distM[n][0], distM[n][1]); 
    ans = std::min(ans, std::min(distR[1][0], distR[1][1]));
    for (int i = 2; i < n; i++) {
      for (int stateM = 0; stateM <= 1; stateM++) {
        for (int stateR = 0; stateR <= 1; stateR++) {
          if (distM[i][stateM] != inf && distR[i][stateR] != inf) {
            ans = std::min(ans, std::max(distM[i][stateM], distR[i][stateR])); 
          }
        }
      }
    } 
    std::cout << (ans == inf ? -1 : ans) << std::endl; 
  }
  return 0; 
}