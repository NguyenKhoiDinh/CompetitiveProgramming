#include <bits/stdc++.h>

using namespace std;
const int inf = 1000000007;
const int MAX_N = 33;

struct Edge
{
  int v;
  long long flow;
  long long C; 
  int rev;
};

class Graph
{
public:
  int V;
  int *level;
  vector< Edge > *adj;
  Graph(int V)
  {
    adj = new vector<Edge>[V];
    this->V = V;
    level = new int[V];
  }

  void addEdge(int u, int v, int C)
  {
    Edge a{v, 0, C, adj[v].size()};
    Edge b{u, 0, 0, adj[u].size()};

    adj[u].push_back(a);
    adj[v].push_back(b);
  }

  bool BFS(int s, int t);
  long long sendFlow(int s, long long flow, int t, int ptr[]);
  long long DinicMaxflow(int s, int t);
};

bool Graph::BFS(int s, int t)
{
  for (int i = 0 ; i < V ; i++)
    level[i] = -1;
  level[s] = 0;
  list< int > q;
  q.push_back(s);
  vector<Edge>::iterator i;
  while (!q.empty())
  {
    int u = q.front();
    q.pop_front();
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
      Edge &e = *i;
      if (level[e.v] < 0 && e.flow < e.C)
      {
        level[e.v] = level[u] + 1;

        q.push_back(e.v);
      }
    }
  }
  return level[t] < 0 ? false : true ;
}

long long Graph::sendFlow(int u, long long flow, int t, int start[])
{
  if (u == t)
    return flow;
  for ( ; start[u] < adj[u].size(); start[u]++)
  {
    Edge &e = adj[u][start[u]];                
    if (level[e.v] == level[u]+1 && e.flow < e.C)
    {
      int curr_flow = min(flow, e.C - e.flow);
      int temp_flow = sendFlow(e.v, curr_flow, t, start);
      if (temp_flow > 0)
      {
        e.flow += temp_flow;
        adj[e.v][e.rev].flow -= temp_flow;
        return temp_flow;
      }
    }
  }

  return 0;
}

long long Graph::DinicMaxflow(int s, int t)
{
  if (s == t)
    return -1;
  long long total = 0;
  while (BFS(s, t) == true) {
    int *start = new int[V+1] {0};
    while (long long flow = sendFlow(s, INT_MAX, t, start))
    total += flow;
  }
  return total;
}

long long cost[26];
string a[MAX_N];
int n, m, c;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int calc(int x, int y) {
  return x * m + y;
}

int main () {
  cin >> n >> m >> c;
  swap(n, m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < c; i++) {
    cin >> cost[i];
  }
  Graph G(5 * n * m);
  int source = 3 * n * m;
  int sink = 3 * n * m + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'B') {
        G.addEdge(source, calc(i, j), inf);
      }
      if (a[i][j] == '.' || a[i][j] == 'B') {
        G.addEdge(calc(i, j), calc(i, j) + n * m, inf);
      }
      else {
        G.addEdge(calc(i, j), calc(i, j) + n * m, cost[a[i][j] - 'a']);
      }
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m) {
          G.addEdge(calc(i, j) + n * m, calc(x, y), inf);
        }
        else {
          G.addEdge(calc(i, j) + n * m, sink, inf);
        }
      }
    }
  }
  int ans = G.DinicMaxflow(source, sink);
  cout << (ans < inf ? ans : -1);
  return 0; 
}