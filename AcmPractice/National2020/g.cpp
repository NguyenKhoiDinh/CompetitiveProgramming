#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int MAX_N = 100005;
const int MAX_LABEL = 500005;
int label[MAX_N];
vector <pair <int, int> > adj[MAX_N];
int n;
int mark[MAX_LABEL];
vector <int> divisors[MAX_LABEL];
vector <int> listGCD;
vector <int> listVerticles[MAX_LABEL];
long long dist[MAX_N];
int height[MAX_N];
int logn[MAX_N];
vector <int> euler;
vector <int> depthArr;
int FAI[MAX_N];
int ptr;
int dp[MAX_N][20];
int p2[20];
int level[MAX_N];

void buildSparseTable(int n) {
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 20; k++) {
      dp[i][k] = -1;
    }
  }
  for (int i = 2; i <= n; i++) {
    dp[i - 1][0] = (depthArr[i] > depthArr[i - 1] ? i - 1 : i);
  }
  for (int k = 1; k < 20; k++) {
    for (int i = 1; i <= n; i++) {
      if (dp[i][k - 1] != -1 && i + p2[k - 1] <= n && dp[i + p2[k - 1]][k - 1] != -1) {
        dp[i][k] = (depthArr[dp[i][k - 1]] > depthArr[dp[i + p2[k - 1]][k - 1]] ? dp[i + p2[k - 1]][k - 1] : dp[i][k - 1]);
      }
      else {
        break;
      }
    }
  }
}

int query(int l, int r) {
  int d = r - l;
  int dx = logn[d];
  if (l == r) {
    return l;
  }
  if (depthArr[dp[l][dx]] > depthArr[dp[r - p2[dx]][dx]]) {
    return dp[r - p2[dx]][dx];
  }
  else {
    return dp[l][dx];
  }
}

void preProcess() {
  p2[0] = 1;
  ptr = 0;
  for (int i = 1; i < 20; i++) {
    p2[i] = p2[i - 1] * 2;
  }
  int val = 1, ptr = 0;
  for (int i = 1; i < MAX_N; i++) {
    logn[i] = ptr - 1;
    if (val == i) {
      val *= 2;
      logn[i] = ptr;
      ptr++;
    }
  }
}

void dfs(int cur, int prev, int dep) {
  if (FAI[cur] == -1) {
    FAI[cur] = ptr;
  }
  level[cur] = dep;
  euler.push_back(cur);
  ptr++;
  for (int i = 0; i < (int) adj[cur].size(); i++) {
    pair <int, int> neighbor = adj[cur][i];
    int x = neighbor.first;
    int weight = neighbor.second;
    if (x != prev) {
      dist[x] = dist[cur] + weight;
      dfs(x, cur, dep + 1);
    }
  }
}

void makeArray() {
  for (int i = 0; i < (int) euler.size(); i++) {
    int x = euler[i];
    depthArr.push_back(level[x]);
  }
}

int lca(int u, int v) {
  if (u == v) {
    return u;
  }
  if (FAI[u] > FAI[v]) {
    swap(u, v);
  }
  return euler[query(FAI[u], FAI[v])];
}

void listDivisors() {
  for (int divisor = 1; divisor < MAX_LABEL; divisor++) {
    for (int mul = divisor; mul < MAX_LABEL; mul += divisor) {
      divisors[mul].push_back(divisor);
    }
  }
}

void createListGcd(int testCase) {
  listGCD.clear();
  for (int i = 0; i < MAX_LABEL; i++) {
    listVerticles[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int) divisors[label[i]].size(); j++) {
      if (mark[divisors[label[i]][j]] != testCase) {
        mark[divisors[label[i]][j]] = testCase;
        listGCD.push_back(divisors[label[i]][j]);
      }
      listVerticles[divisors[label[i]][j]].push_back(i);
    }
  }
}

void solve() {
  vector <int> listVertex;
  long long ans = -1;
  for (int i = 0; i < (int) listGCD.size(); i++) {
    int gcd = listGCD[i];
    listVertex = listVerticles[gcd];
    if ((int) listVertex.size() < 2) {
      continue;
    }
    int vertex = -1;
    long long maxDist = -1;
    int start = listVertex[0];
    for (int j = 1; j < (int) listVertex.size(); j++) {
      int v = listVertex[j];
      int LCA = lca(start, v);
      long long distance = dist[start] + dist[v] - 2LL * dist[LCA];
      if (maxDist < distance) {
        maxDist = distance;
        vertex = v;
      }
    }
    maxDist = -1;
    for (int j = 0; j < (int) listVertex.size(); j++) {
      int v = listVertex[j];
      if (v == vertex) {
        continue;
      }
      int LCA = lca(vertex, v);
      long long distance = dist[vertex] + dist[v] - 2LL * dist[LCA];
      if (maxDist < distance) {
        maxDist = distance;
      }
    }
    if (ans < 1LL * maxDist * gcd) {
      ans = 1LL * maxDist * gcd;
    }
  }
  printf("%lld\n", ans);
}

int main () {
  listDivisors();
  preProcess();
  int testCase = 0;
  while (true) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    testCase++;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      FAI[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &label[i]);
    }
    createListGcd(testCase);
    for (int i = 1; i < n; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
    euler.clear();
    depthArr.clear();
    ptr = 0;
    dist[1] = 0;
    dfs(1, -1, 0);
    makeArray();
    buildSparseTable((int) depthArr.size());
    solve();
  }
  return 0;
}