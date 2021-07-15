#include <bits/stdc++.h>

using namespace std; 
const int MAX_N = 55; 
string a[MAX_N];
int n, m, A, B;
int vertex[MAX_N][MAX_N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Edge
{
  int v;
  int flow;
  int C; 
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
  int sendFlow(int s, int flow, int t, int ptr[]);
  int DinicMaxflow(int s, int t);
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

int Graph::sendFlow(int u, int flow, int t, int start[])
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

int Graph::DinicMaxflow(int s, int t)
{
  if (s == t)
    return -1;
  int total = 0;
  while (BFS(s, t) == true) {
    int *start = new int[V+1] {0};
    while (int flow = sendFlow(s, INT_MAX, t, start))
    total += flow;
  }
  return total;
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> m >> A >> B;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int id = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      id++;
      vertex[i][j] = id;
    }
  }
  int source = 0; 
  int sink = n * m + 2;
  Graph G(n * m + 10);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        G.addEdge(source, vertex[i][j], B); 
      }
      else {
        G.addEdge(vertex[i][j], sink, B);
      }
    }
  } 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = i, y = j; 
      for (int t = 0; t < 4; t++) {
        int nextx = x + dx[t];
        int nexty = y + dy[t];
        if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m) {
          {
            G.addEdge(vertex[x][y], vertex[nextx][nexty], A);
          }
        }
      }
    }
  }
  cout << G.DinicMaxflow(source, sink);
  return 0;
}