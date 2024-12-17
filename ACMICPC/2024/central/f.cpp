#include <bits/stdc++.h>
using namespace std;
const int inf = 300005;   
int n,source = 0, sink = 10004; 
int work[10005];
int d[10005];

struct edge {
  int to,rev,flow,cap;
};

vector <edge> adj[10005];

void addedge(int u, int v, int cap)
{                                                   
  edge a = {v, (int) adj[v].size(), 0LL, cap};
  edge b = {u, (int) adj[u].size(), 0LL, 0LL};
  adj[u].push_back(a); 
  adj[v].push_back(b);
}

bool bfs()
{
  queue <int> myqueue;
  memset(d, -1, sizeof(d)); 
  myqueue.push(source); 
  d[source] = 0;
  while (myqueue.empty() == false)
  {
    int u = myqueue.front();
    myqueue.pop();
    for (edge e : adj[u])
    {
      int v = e.to;
      if (d[v] == -1 and e.flow < e.cap)
      {                                                                
        d[v] = d[u] + 1;
        myqueue.push(v);
      }
    }
  }
  return d[sink] > 0;
}

int dfs(int u,int p)
{
  if (u == sink) return p;
  for (int &s = work[u]; s < adj[u].size(); s++)
  {
    edge &e = adj[u][s];
    int v = e.to;
    if (d[v] == d[u] + 1 and e.flow < e.cap)
    {
      int f = dfs(v,min(p , e.cap - e.flow));
      if (f > 0) 
      {
        e.flow += f, adj[v][e.rev].flow -= f;
        return f;
      }
    }
  }
  return 0;
}

void calc()
{
  int res = 0;
  while (bfs() == true)
  {                       
    memset(work, 0, sizeof(work)); 
    while (int del = dfs(source,inf)) res += del;
  }
  cout << res << endl;
}      
 
int main () {
  int numTest;
  scanf("%d", &numTest); 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int nA, nB, nC; 
    scanf("%d %d %d %d", &n, &nA, &nB, &nC); 
    for (int i = 0; i < 10005; i++) {
      adj[i].clear(); 
    }
    addedge(n + 1, sink, nA); 
    addedge(n + 2, sink, nB); 
    addedge(n + 3, sink, nC); 
    for (int i = 1; i <= 3; i++) {
      int m;
      scanf("%d", &m); 
      while (m--) {
        int u;
        scanf("%d", &u); 
        addedge(u, i + n, 1);  
      }
    }
    for (int i = 1; i <= n; i++) {
      addedge(source, i, 1);  
    }
    calc();   
  }
  return 0;
}