#include <bits/stdc++.h>

using namespace std;
vector <int> adj[100005];
int V, E;
int dp[100005];
int countIn[100005];
bool visited[100005];
vector <int> topo;

void DFS(int u) {
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      DFS(v);
    }
  }
  topo.push_back(u);
}

int main () {
  cin >> V >> E;
  for (int i = 1; i <= E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    countIn[v]++;
  }
  for (int i = 1; i <= V; i++) {
    if (countIn[i] == 0) {
      DFS(i);
    }
  }
  reverse(topo.begin(), topo.end());
  for (int i = 0; i < (int) topo.size(); i++) {
    int u = topo[i];
    for (int j = 0; j < (int) adj[u].size(); j++) {
      int v = adj[u][j];
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }
  int res = -1;
  for (int i = 1; i <= V; i++) {
    if (res < dp[i]) {
      res = dp[i];
    }
  }
  cout << res;
  return 0;
}