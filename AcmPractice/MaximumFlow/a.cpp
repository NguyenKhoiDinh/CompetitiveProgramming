#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 505; 

int work[MAX_N], dist[MAX_N];
const int inf = INT_MAX;
int n, m, source, sink; 

struct edge {
  int to, rev;
  int flow, cap;
};

struct Edge {
  int u, v, w; 
  bool operator < (const Edge &hs) {
    return (u < hs.u || (u == hs.u && v < hs.v)); 
  }
};
 
vector <edge> adj[MAX_N];
 
void addEdge(int u, int v, int cap) {
  edge a = {v, (int) adj[v].size(), 0, cap};
  edge b = {u, (int) adj[u].size(), 0, 0};
  adj[u].push_back(a);
  adj[v].push_back(b);
}
 
bool BFS() {
  queue <int> myqueue;
  memset(dist, -1, sizeof(dist));
  myqueue.push(source);
  dist[source] = 0;
  while(myqueue.empty() == false) {
    int u = myqueue.front();
    myqueue.pop();
    for (int i = 0; i < (int) adj[u].size(); i++) {
      edge e = adj[u][i];
      int v = e.to;
      if (dist[v] < 0 && e.flow < e.cap) {
        dist[v] = dist[u] + 1;
        myqueue.push(v);
      }
    }
  }
  return dist[sink] > 0;
}
 
int DFS(int u, int f) {
  if (u == sink) {
    return f;
  }
  for (int &s = work[u]; s < (int) adj[u].size(); s++) {
    edge &e = adj[u][s];
    int v = e.to;
    if (dist[v] == dist[u] + 1 && e.flow < e.cap) {
      int df = DFS(v, min(f, e.cap - e.flow));
      if (df > 0) {
        e.flow += df;
        adj[v][e.rev].flow -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow() {
  int res = 0;
  while (BFS() == true) {
    memset(work, 0, sizeof(work)); 
    while (int del = DFS(source, inf)) {
      res += del;
    }
  }
  return res;
}
                       
vector <Edge> save;  

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout); 
  scanf("%d %d %d %d", &n, &m, &source, &sink); 
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w); 
    addEdge(u, v, w);
    save.push_back((Edge) {u, v, w}); 
  }
  int maxflow = maxFlow();      
  vector <Edge> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) adj[i].size(); j++) {
      if (adj[i][j].flow > 0) {
        ans.push_back((Edge) {i, adj[i][j].to, adj[i][j].flow});
      }
    }
  }
  cout << n << ' ' << maxflow << ' ' << (int) ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].u << ' ' << ans[i].v << ' ' << ans[i].w << endl;
  }  
  return 0;
}