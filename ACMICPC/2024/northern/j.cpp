#include <iostream> 
#include <utility> 
#include <math.h> 
#include <vector> 
#include <queue>
#include <tuple>
#define int long long
struct edge {
  int to, capacity, flow, id; 
};
struct Dinic {
  int inf; 
  int numbVertex;  
  std::vector <std::vector <edge> > adj; 
  std::vector <int> level; 
  int source, sink; 
  Dinic(int _numbVertex, int _source, int _sink, int _inf) {
    numbVertex = _numbVertex;
    source = _source;
    sink = _sink;  
    adj.clear(); 
    adj.resize(numbVertex); 
    level.clear(); 
    level.resize(numbVertex);
    inf = _inf;  
  }
  void addEdge(int u, int v, int weight) {
    int szu = (int) adj[u].size(); 
    int szv = (int) adj[v].size();  
    adj[u].push_back((edge) {v, weight, 0, szv});
    adj[v].push_back((edge) {u, 0, 0, szu}); 
  }
  bool bfs() {
    for (int i = 0; i < numbVertex; i++) {
      level[i] = -1; 
    }  
    std::queue <int> myqueue; 
    myqueue.push(source); 
    level[source] = 0; 
    while (myqueue.empty() == false) {
      int u = myqueue.front(); 
      myqueue.pop(); 
      for (int i = 0; i < (int) adj[u].size(); i++) {
        edge neighbor = adj[u][i]; 
        if (neighbor.flow < neighbor.capacity && level[neighbor.to] == -1) {
          level[neighbor.to] = level[u] + 1; 
          myqueue.push(neighbor.to); 
        }
      }
    }                                     
    return (level[sink] != -1);
  }
  int sendFlow(int u, int sink, int currentFlow, std::vector <int> &start) {
    if (u == sink) {
      return currentFlow; 
    }
    for (; start[u] < (int) adj[u].size(); start[u]++) {
      edge &neighbor = adj[u][start[u]]; 
      if (level[neighbor.to] == level[u] + 1 && neighbor.flow < neighbor.capacity) {
        int flow = sendFlow(neighbor.to, sink, std::min(currentFlow, neighbor.capacity - neighbor.flow), start); 
        if (flow > 0) {
          neighbor.flow += flow; 
          edge &rev = adj[neighbor.to][neighbor.id]; 
          rev.flow -= flow; 
          return flow;
        } 
      }                
    }
    return 0; 
  }
  int dinicMaxFlow() {
    int ret = 0LL;
    while (bfs() == true) {
      while (true) {
        std::vector <int> start(numbVertex, 0); 
        int flow = sendFlow(source, sink, inf, start); 
        if (flow == 0) {
          break; 
        }
        ret += flow; 
      } 
    }    
    return ret; 
  }
};
int n, m, source = 0, sink; 
struct sensor {
  long long x, y; 
}; 
sensor a[255]; 
int L, W; 

signed main () {
  std::cin >> L >> W >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x >> a[i].y; 
  }
  sink = 3 * n + 10; 
  Dinic D(3 * n + 100, source, sink, 1000000007);
  for (int i = 1; i <= n; i++) {
    D.addEdge(i, i + n, 1); 
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].y <= 100) {
      D.addEdge(source, i, 1000000007); 
    }
  } 
  for (int i = 1; i <= n; i++) {
    if (W - a[i].y <= 100) {
      D.addEdge(i + n, sink, 1000000007);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((1LL * (a[i].x - a[j].x) * (a[i].x - a[j].x) + 1LL * (a[i].y - a[j].y) * (a[i].y - a[j].y)) <= 40000) {
        D.addEdge(i + n, j, 1000000007); 
        D.addEdge(j + n, i, 1000000007); 
      }
    }
  }
  std::cout << D.dinicMaxFlow(); 
  return 0;
}