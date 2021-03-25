#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 100005;
vector <int> adj[MAX_N];
int V, E;
int dp[MAX_N];
int countIn[MAX_N];
bool visited[MAX_N];
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