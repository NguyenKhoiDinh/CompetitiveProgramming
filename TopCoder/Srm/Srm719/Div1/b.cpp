#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005;
int dp[MAX_N], sum[MAX_N];
vector <int> adj[MAX_N];
vector <int> a;

void DFSSum(int u, int father) {
  sum[u] = a[u];
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    sum[u] += max(sum[v], 0);
  }
}

void DFS(int u, int father) {
  dp[u] = sum[u];
  int sumValue = 0;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    sumValue += max(dp[v], 0);
  }
  dp[u] = max(dp[u], sumValue);
}

class OwaskiAndTree {
  public:
  int maximalScore(vector <int> parent, vector <int> pleasure) {
    a = pleasure;
    int n = (int) a.size();
    for (int i = 0; i < (int) parent.size(); i++) {
      adj[parent[i]].push_back(i + 1);
      adj[i + 1].push_back(parent[i]);
    }
    DFSSum(0, -1);
    DFS(0, -1);
    return dp[0];
  }
};

int main () {
  return 0;
}