#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
const int DELTA = 1005;
vector <int> adj[MAX_N];
int dp[MAX_N][DELTA * 2 + 105];
vector <int> sumValue;
bool visited[MAX_N];
int sum = 0;

void dfs(int u, int sign, vector <int> &a, vector <string> &road) {
  sum += sign * a[u];
  visited[u] = true;
  for (int v = 0; v < (int) road.size(); v++) {
    if (road[u][v] == '1') {
      if (visited[v] == false) {
        dfs(v, -sign, a, road);
      }
    }
  }
}

class MagicianTour {
  public:
  int bestDifference(vector <string> roads, vector <int> a) {
    int n = (int) roads.size();
    for (int u = 0; u < n; u++) {
      visited[u] = false;
    }
    for (int u = 0; u < n; u++) {
      if (visited[u] == false) {
        sum = 0;
        dfs(u, 1, a, roads);
        sumValue.push_back(sum);
      }
    }
    int sz = (int) sumValue.size();
    dp[0][DELTA] = 1;
    for (int i = 0; i <= sz; i++) {
      for (int val = 0; val <= 2 * DELTA; val++) {
        if (dp[i][val] == 0) {
          continue;
        }
        dp[i + 1][val + sumValue[i]] = 1;
        dp[i + 1][val - sumValue[i]] = 1;
      }
    }
    int res = 3 * DELTA;
    for (int val = 0; val <= 2 * DELTA; val++) {
      if (dp[sz][val] == 1) {
        res = min(res, abs(val - DELTA));
      }
    }
    return res;
  }
};
MagicianTour M;

int main () {
  cout << M.bestDifference({"01","10"},
{15,20});
  return 0;
}