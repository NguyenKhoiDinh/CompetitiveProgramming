#include <iostream> 
#include <utility> 
#include <math.h> 
#include <vector> 
#include <queue>
#include <tuple>
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

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::vector <long long> a;
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    int source = 0; 
    int sink = n + 70; 
    Dinic D(n + 100, source, sink, 1000000007); 
    for (int i = 0; i < n; i++) {
      D.addEdge(source, i + 1, 1); 
      for (long long b = 0; b < 60; b++) {
        if ((a[i] & (1LL << b)) > 0) {
          D.addEdge(i + 1, b + 1 + n, 1);
        }
      }
    }
    for (int b = 0; b < 60; b++) {
      D.addEdge(b + 1 + n, sink, 1); 
    }
    std::cout << n - D.dinicMaxFlow() << std::endl; 
  }
  return 0; 
}