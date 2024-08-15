#include <bits/stdc++.h>
using namespace std; 
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};
 
struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
 
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
 
    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, cap);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
 
    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }
 
    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
 
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
int n, m;
std::vector <long long> adj[105]; 

int main () {
  scanf("%d %d", &n, &m); 
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v); 
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  const long long inf = 1000000000007LL;  
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int source = 0; 
      int sink = 2 * n + 4;
      Dinic D(2 * n + 20, source, sink);
      D.add_edge(source, i, inf);
      D.add_edge(j, sink, inf);
      for (int x = 1; x <= n; x++) {
        if (x == i) {
          D.add_edge(x, x + n, inf); 
        }
        else if (x == j) {
          D.add_edge(x, x + n, inf); 
        }
        else {
          D.add_edge(x, x + n, 1); 
        }
      }
      for (int x = 1; x <= n; x++) {
        for (int k = 0; k < (int) adj[x].size(); k++) {
          int y = adj[x][k];
          D.add_edge(x + n, y, 1); 
          D.add_edge(y + n, x, 1);   
        }
      }
      long long maxFlow = D.flow(); 
      if (maxFlow < n / 2) {
        printf("-1");
        return 0; 
      } 
    }
  }
  printf("1"); 
  return 0; 
}