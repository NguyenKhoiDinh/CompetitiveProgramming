#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 305; 
const long long inf = 1000000000007LL; 
int numTest;
int n, m, S, R; 
long long dist[MAX_N][MAX_N];
vector <int> adj[MAX_N];
int dest[MAX_N];
vector <int> listStones[MAX_N];
vector <int> listRecipe[MAX_N];

priority_queue <pair <long long, pair <int, int> >, vector <pair <long long, pair <int, int> > >, greater <pair <long long, pair <int, int> > > > pq;

void dijkstra() {
  long long ans = inf;
  while (!pq.empty()) {
    pair <long long, pair <int, int> > e = pq.top();
    pq.pop(); 
    int stone = e.second.first; 
    int node = e.second.second;
    if (e.first != dist[stone][node]) {
      continue; 
    }
    for (int i = 0; i < (int) listRecipe[stone].size(); i++) {
      int r = listRecipe[stone][i];
      long long sum = 0LL;
      for (int j = 0; j < (int) listStones[r].size(); j++) {
        int stone = listStones[r][j];
        sum += dist[stone][node];
      }
      int product = dest[r];
      if (dist[product][node] > sum) {
        dist[product][node] = sum; 
        pq.push(make_pair(dist[product][node], make_pair(product, node)));
      }
    }
    for (int i = 0; i < (int) adj[node].size(); i++) {
      int nextNode = adj[node][i]; 
      if (dist[stone][nextNode] > dist[stone][node] + 1) {
        dist[stone][nextNode] = dist[stone][node] + 1;
        pq.push(make_pair(dist[stone][nextNode], make_pair(stone, nextNode)));
      }
    }
  } 
  for (int i = 1; i <= n; i++) {
    ans = min(ans, dist[1][i]);
  }
  if (ans == inf) {
    ans = -1; 
  }
  printf("%lld\n", ans);
}

void init() {
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 1; i <= R; i++) {
    listStones[i].clear(); 
  }
  for (int i = 1; i <= S; i++) {
    listRecipe[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = inf; 
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    printf("Case #%d: ", testCase);
    scanf("%d %d %d %d", &n, &m, &S, &R);
    init();
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      int numStones; 
      scanf("%d", &numStones);
      for (int j = 1; j <= numStones; j++) {
        int stone; 
        scanf("%d", &stone);
        dist[stone][i] = 0LL; 
        pq.push(make_pair(0LL, make_pair(stone, i)));
      }
    }
    for (int i = 1; i <= R; i++) {
      int cnt;
      scanf("%d", &cnt);
      while (cnt--) {
        int stone;
        scanf("%d", &stone);
        listStones[i].push_back(stone);
        listRecipe[stone].push_back(i);
      }
      scanf("%d", &dest[i]);
    }
    dijkstra();
  }
  return 0;
}