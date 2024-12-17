#include <iostream>
#include <queue> 
#include <math.h> 
#include <vector> 
int dist[3005][3005];
std::vector <int> adj[3005];
int n, m; 
int s1, t1, l1;
int s2, t2, l2; 

int main () {
  std::cin >> n >> m; 
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      dist[u][v] = -1; 
    }
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  std::cin >> s1 >> t1 >> l1;
  std::cin >> s2 >> t2 >> l2;
  for (int u = 1; u <= n; u++) {
    std::queue <int> myqueue;
    myqueue.push(u);
    dist[u][u] = 0;
    while (myqueue.empty() == false) {
      int f = myqueue.front();
      myqueue.pop();
      for (int i = 0; i < (int) adj[f].size(); i++) {
        int to = adj[f][i]; 
        if (dist[u][to] == -1) {
          dist[u][to] = dist[u][f] + 1; 
          myqueue.push(to); 
        }
      }
    } 
  }
  if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
    std::cout << -1; 
  }
  else {
    int ans = dist[s1][t1] + dist[s2][t2];
    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= n; v++) {
        if (dist[s1][u] + dist[u][v] + dist[v][t1] <= l1 && dist[s2][u] + dist[u][v] + dist[v][t2] <= l2) {
          ans = std::min(ans, dist[s1][u] + dist[u][v] + dist[v][t1] + dist[s2][u] + dist[v][t2]);
        }
        if (dist[s1][u] + dist[u][v] + dist[v][t1] <= l1 && dist[s2][v] + dist[v][u] + dist[u][t2] <= l2) {
          ans = std::min(ans, dist[s1][u] + dist[u][v] + dist[v][t1] + dist[s2][v] + dist[u][t2]);
        } 
      }
    }
    std::cout << m - ans; 
  }
  return 0; 
}
