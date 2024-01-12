#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int MAX_N = 4096;
const int SHIFT = 2048;
bool visited[MAX_N][MAX_N];
vector <int> adj[MAX_N];
int n, m;

void dfs(int start, int u) {
  visited[start][u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[start][v] == false) {
      dfs(start, v);
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int p, q;
    cin >> p >> q;
    adj[SHIFT - p].push_back(SHIFT + q);
    adj[SHIFT - q].push_back(SHIFT + p);
  }
  for (int i = 1; i <= n; i++) {
    dfs(SHIFT + i, SHIFT + i);
    dfs(SHIFT - i, SHIFT - i);
  }
  int ans = 3;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (visited[SHIFT + i][SHIFT - j] == true) {
        if (i == j) {
          ans = min(ans, visited[SHIFT - i][SHIFT + j] == true ? 0 : 1);
        }
        else {
          ans = min(ans, visited[SHIFT + i][SHIFT + j] == true ? 1 : 2);
        }
      }
    }
  }
  if (ans == 3) {
    ans = -1;
  }
  cout << ans;
  return 0;
}