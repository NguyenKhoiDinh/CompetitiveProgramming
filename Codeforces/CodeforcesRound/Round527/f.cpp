#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005;

long long dpIn[MAX_N], dpOut[MAX_N], sum[MAX_N];
long long a[MAX_N];
int n;
vector <int> adj[MAX_N];

void DFSOut(int u, int father) {
  sum[u] = a[u];
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    DFSOut(v, u);
    dpOut[u] += sum[v] + dpOut[v];
    sum[u] += sum[v];
  }
}

void DFSIn(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    dpIn[v] = (sum[1] - sum[v]) + dpIn[u] + (dpOut[u] - dpOut[v] - sum[v]);
    DFSIn(v, u);
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFSOut(1, -1);
  DFSIn(1, -1);
  long long ans = 0;
  for (int u = 1; u <= n; u++) {
    ans = max(ans, dpOut[u] + dpIn[u]);
  }
  printf("%lld", ans);
  return 0;
}