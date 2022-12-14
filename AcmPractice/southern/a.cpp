#include <bits/stdc++.h>

using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < n; ++i)

const int INF = 1000000000, MN = 205;
 
struct Edge {
    int a, b, cap, flow;
};

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;

    MaxFlow(int n) : n(n), d(n), ptr(n), q(n), g(n) {
        e.clear();
        REP(i,n) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap) {
        Edge e1 = { a, b, cap, 0 };
        Edge e2 = { b, a, 0, 0 };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            REP(i,n) ptr[i] = 0;
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }

private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        REP(i,n) d[i] = -1;
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            REP(i,g[v].size()) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};

struct GomoryHu {
    int ok[MN], cap[MN][MN];
    int answer[MN][MN], parent[MN];
    int n;
    MaxFlow flow;

    GomoryHu(int n) : n(n), flow(n) {
        for(int i = 0; i < n; ++i) ok[i] = parent[i] = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cap[i][j] = 0, answer[i][j] = INF;
    }

    void addEdge(int u, int v, int c) {
        cap[u][v] += c;
    }

    void calc() {
        for(int i = 0; i < n; ++i) parent[i]=0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                answer[i][j]=2000111000;

        for(int i = 1; i <= n-1; ++i) {
            flow = MaxFlow(n);
            REP(u,n) REP(v,n)
                if (cap[u][v])
                    flow.addEdge(u, v, cap[u][v]);

            int f = flow.getMaxFlow(i, parent[i]);

            bfs(i);
            for(int j = i+1; j < n; ++j)
                if (ok[j] && parent[j]==parent[i])
                    parent[j]=i;
            
            answer[i][parent[i]] = answer[parent[i]][i] = f;
            for(int j = 0; j < i; ++j)
                answer[i][j]=answer[j][i]=min(f,answer[parent[i]][j]);
        }
    }
    void bfs(int start) {
        memset(ok,0,sizeof ok);
        queue<int> qu;
        qu.push(start);
        while (!qu.empty()) {
            int u=qu.front(); qu.pop();
            for(int xid = 0; xid < flow.g[u].size(); ++xid) {
                int id = flow.g[u][xid];
                int v = flow.e[id].b, fl = flow.e[id].flow, cap = flow.e[id].cap;
                if (!ok[v] && fl < cap) {
                    ok[v]=1;
                    qu.push(v);
                }
            }
        }
    }
};

const int N = 211;
int c[N][N];

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  // freopen("TaskA.INP", "r", stdin);
  // freopen("TaskA.OUT", "w", stdout);

  int tc;
  cin >> tc;
  int demtest = 0;
  while (tc--) {
    demtest++;
    int n;
    cin >> n;
    GomoryHu gh(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> c[i][j];
        if (i != j) {
          gh.addEdge(i, j, c[i][j]);
        }
      }
    }
    gh.calc();

    cout << "Case #" << demtest << ":" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          cout << 0 << ' ';
          continue;
        }
        cout << gh.answer[i][j] << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}