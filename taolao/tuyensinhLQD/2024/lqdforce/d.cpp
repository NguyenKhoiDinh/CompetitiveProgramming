#include <iostream> 
#include <utility> 
#include <math.h> 
#include <vector> 
#include <queue>
#include <tuple>
#include <algorithm> 
#include <set>
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
int n, numQueries, source, sink;
int a[105];  
std::pair <int, int> save[105]; 

int main () {       
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 1; i <= numQueries; i++) {
    std::cin >> save[i].first >> save[i].second; 
    if (save[i].first % 2 == 0) {
      std::swap(save[i].first, save[i].second); 
    }
  }
  std::set <int> S; 
  for (int i = 1; i <= n; i++) {
    int tmp = a[i];
    for (int j = 2; j <= (int) std::sqrt(a[i]); j++) {
      while (tmp % j == 0) {
        S.insert(j); 
        tmp /= j; 
      }
    }  
    if (tmp > 1) {
      S.insert(tmp); 
    }
  }
  int ans = 0; 
  for (std::set <int>::iterator it = S.begin(); it != S.end(); it++) {
    int value = *it; 
    int source = 0; 
    int sink = n + 5; 
    Dinic D(n + 10, source, sink, 1000000007);
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        int tmp = a[i];
        int numb = 0;
        while (tmp % value == 0) {
          numb++;
          tmp /= value;  
        } 
        D.addEdge(source, i, numb); 
      }
      else {
        int tmp = a[i];
        int numb = 0;
        while (tmp % value == 0) {
          numb++;
          tmp /= value; 
        }
        D.addEdge(i, sink, numb); 
      }
    }
    for (int j = 1; j <= numQueries; j++) {
      int gcd = std::__gcd(a[save[j].first], a[save[j].second]);
      int numb = 0;
      while (gcd % value == 0) {
        numb++;
        gcd /= value; 
      } 
      if (numb > 0) {
        D.addEdge(save[j].first, save[j].second, numb); 
      }
    }
    ans += D.dinicMaxFlow();  
  }
  std::cout << ans;
  return 0;
}