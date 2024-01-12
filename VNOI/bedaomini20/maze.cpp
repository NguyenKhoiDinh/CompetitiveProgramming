#include <iostream> 
#include <math.h> 
#include <vector> 
#include <queue>
int n, m;
int a[100005];
std::vector <int> adj[100005];
int dist[100005];  
bool ok[100005];

void bfs(int start) {
  if (ok[start] == false) {
    return; 
  }
  std::queue <int> myqueue; 
  myqueue.push(start);
  dist[start] = 0; 
  while (myqueue.empty() == false) {
    int u = myqueue.front(); 
    myqueue.pop();
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i]; 
      if (ok[v] == true && dist[v] == -1) {
        dist[v] = dist[u] + 1; 
        myqueue.push(v); 
      }
    }
  }
}

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];  
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = n + 5; 
  int lo = 1; 
  int hi = n; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    for (int i = 1; i <= n; i++) {
      ok[i] = false;
      dist[i] = -1; 
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] <= mid) {
        ok[i] = true;   
      }
    }
    bfs(1);
    if (dist[n] != -1 && dist[n] + 1 <= mid) {
      ans = std::min(ans, mid - dist[n] - 1); 
      hi = mid - 1; 
    }
    else {
      lo = mid + 1; 
    }
  }
  lo = 1; 
  hi = n; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    for (int i = 1; i <= n; i++) {
      ok[i] = false;
      dist[i] = -1; 
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] <= mid) {
        ok[i] = true;   
      }
    }
    bfs(1);
    if (dist[n] != -1 && dist[n] + 1 > mid) {
      ans = std::min(ans, dist[n] + 1 - mid); 
      lo = mid + 1; 
    }
    else {
      hi = mid - 1; 
    }
  }
  std::cout << (ans == n + 5 ? -1 : ans);
  return 0; 
}