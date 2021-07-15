#include <bits/stdc++.h>

using namespace std; 
const int MAX_N = 1005;
const long long inf = 1000000000000007LL;
int n; 
long long a[MAX_N];

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

  void addEdge(int u, int v, long long C)
  {
    Edge a{v, 0, C, adj[v].size()};
    Edge b{u, 0, 0LL, adj[u].size()};

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
      long long curr_flow = min(flow, e.C - e.flow);
      long long temp_flow = sendFlow(e.v, curr_flow, t, start);
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
  int total = 0;
  while (BFS(s, t) == true) {
    int *start = new int[V+1] {0};
    while (long long flow = sendFlow(s, inf, t, start))
    total += flow;
  }
  return total;
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n;
  Graph G(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  sort(a + 1, a + n + 1); 
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      long long gcd = __gcd(a[i], a[j]);
      if (gcd == 1) {
        continue;
      }
      G.addEdge(i, j, gcd); 
      G.addEdge(j, i, gcd);
    }
  }
  cout << G.DinicMaxflow(1, n);
  return 0; 
}