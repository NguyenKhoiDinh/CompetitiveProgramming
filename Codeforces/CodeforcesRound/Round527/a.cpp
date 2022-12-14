#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005;

long long dpIn[MAX_N], dpOut[MAX_N];
long long a[MAX_N];
int n;
vector <int> adj[MAX_N];

void DFSOut(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    DFSOut(v, u);
    dpOut[u] += a[v] + dpOut[v] * 2LL;
  }
}

void DFSIn(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    dpIn[v] = a[u] + 2LL * dpIn[u] + 2LL * (dpOut[u] - dpOut[v]);
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
  for (int u = 1; u <= n; u++) {
    cout << dpOut[u] << "   ";
  }
  cout << endl;
  DFSIn(1, -1);
  for (int u = 1; u <= n; u++) {
    cout << dpIn[u] << "   ";
  }
  cout << endl;
  long long ans = 0;
  for (int u = 1; u <= n; u++) {
    ans = max(ans, dpOut[u] + dpIn[u]);
  }
  printf("%lld", ans);
  return 0;
}