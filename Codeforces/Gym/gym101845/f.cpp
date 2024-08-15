#include <iostream> 
#include <utility> 
#include <math.h> 
#include <vector> 
#include <queue>
#include <string> 
#include <tuple>
struct edge {
  int to, capacity, flow, id; 
};
struct Dinic {
  int inf; 
  int numbVertex;
  std::vector <int> pos;   
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
    pos.clear();
    pos.resize(numbVertex, 0); 
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
  int sendFlow(int u, int sink, int currentFlow) {
    if (u == sink) {
      return currentFlow; 
    }
    for (; pos[u] < (int) adj[u].size(); pos[u]++) {
      edge &neighbor = adj[u][pos[u]]; 
      if (level[neighbor.to] == level[u] + 1 && neighbor.flow < neighbor.capacity) {
        int flow = sendFlow(neighbor.to, sink, std::min(currentFlow, neighbor.capacity - neighbor.flow)); 
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
      for (int i = 0; i < numbVertex; i++) {
        pos[i] = 0; 
      }
      while (true) {
        int flow = sendFlow(source, sink, inf); 
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
  int n; 
  std::cin >> n;
  int source = 0; 
  int sink = n + 30; 
  Dinic D(n + 50, source, sink, 1000000007); 
  for (int i = 1; i <= n; i++) {
    std::vector <int> cnt(26, 0); 
    for (int j = 0; j < 3; j++) {
      std::string s;
      std::cin >> s;
      for (int k = 0; k < (int) s.size(); k++) {
        cnt[s[k] - 'A']++; 
      } 
    }
    int maxValue = -1;
    for (int j = 0; j < 26; j++) {
      maxValue = std::max(maxValue, cnt[j]); 
    }
    for (int j = 0; j < 26; j++) {
      if (cnt[j] == maxValue) {
        D.addEdge(n + j + 1, i, 1); 
      }
    }
    D.addEdge(i, sink, 1); 
  }
  int k; 
  std::cin >> k;
  for (int j = 1; j <= 26; j++) {
    D.addEdge(source, n + j, k); 
  }
  std::cout << D.dinicMaxFlow(); 
  return 0; 
}