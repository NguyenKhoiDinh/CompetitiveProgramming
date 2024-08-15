#include <iostream>
#include <string>
#include <bitset> 
#include <vector>
#include <algorithm>
#include <queue>
int n; 
std::string s[505];
const int inf = 1000; 
struct edge {
  int to, capacity, flow, id; 
};
std::vector <int> adj[505]; 
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
bool check(const std::string &s1, const std::string &s2) {
  if ((int) s1.size() != (int) s2.size()) {
    return false; 
  }
  std::vector <int> p;
  for (int i = 0; i < (int) s1.size(); i++) {
    if (s1[i] != s2[i]) {
      p.push_back(i); 
    }  
  }  
  if ((int) p.size() != 2) {
    return false; 
  }
  if (s1[p[0]] == s2[p[1]] && s1[p[1]] == s2[p[0]]) {
    return true; 
  }
  return false; 
}
int color[505]; 
void dfsColor(int u, int c) {
  color[u] = c;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (color[v] == -1) {
      dfsColor(v, 1 - c); 
    }
  }  
}

int main () {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> s[i]; 
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (check(s[i], s[j]) == true) {
        adj[i].push_back(j);
        adj[j].push_back(i);    
      }
    }
  }
  for (int i = 0; i < n; i++) {
    color[i] = -1; 
  } 
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      dfsColor(i, 0); 
    }
  } 
  int source = 0, sink = n + 5; 
  Dinic D(n + 10, source, sink, inf);
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      D.addEdge(source, i + 1, 1); 
    }
    else {
      D.addEdge(i + 1, sink, 1); 
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) adj[i].size(); j++) {
      int nxt = adj[i][j]; 
      int u = i + 1;
      int v = adj[i][j] + 1; 
      if (color[u - 1] > color[v - 1]) {
        std::swap(u, v); 
      }
      D.addEdge(u, v, 1); 
    }  
  }
  std::cout << n - D.dinicMaxFlow(); 
  return 0; 
}
