const int N = (int)1e4+10;
int n,source=0,sink=1e4+4,work[N],d[N];

struct edge {
	int to,rev,flow,cap;
};

vector<edge> g[N];

void addedge(int u, int v, int cap)
{
	edge a = {v,(int)g[v].size(),0LL,cap};
	edge b = {u,(int)g[u].size(),0LL,0LL};
	g[u].pb(a); g[v].pb(b);
}

bool BFS()
{
	queue<int> q;
	fill(d,-1);
	q.push(source); d[source] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (edge e : g[u])
		{
			int v = e.to;
			if (d[v] < 0 and e.flow < e.cap)
			{
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
	return d[sink] > 0;
}

int DFS(int u,int p)
{
	if (u == sink) return p;
	for (int &s = work[u]; s < g[u].size(); s++)
	{
		edge &e = g[u][s];
		int v = e.to;
		if (d[v] == d[u]+1 and e.flow < e.cap)
		{
			int f = DFS(v,min(p,e.cap-e.flow));
			if (f > 0) 
			{
				e.flow += f, g[v][e.rev].flow -= f;
				return f;
			}
		}
	}
	return 0;
}

void calc()
{
	int res = 0;
	while (BFS())
	{
		fill(work,0);
		while (int del = DFS(source,oo)) res += del;
	}
	cout << res << endl;
}