#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
const int inf = 100005;
int dist[MAX_N][MAX_N];

class MapleTreeEasy {
  public:
  long long count(vector <int> p) {
    int n = (int) p.size();
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dist[i][j] = inf;
        if (i == j) {
          dist[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      dist[p[i]][i + 1] = 1;
      dist[i + 1][p[i]] = 1;
    }
    for (int k = 0; k <= n; k++) {
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    long long ans = n + 1;
    for (int u = 0; u < n; u++) {
      for (int v = u + 1; v <= n; v++) {
        ans += 1LL << (dist[u][v] - 1);
      }
    }
    return ans;
  }
};

int main () {
  return 0;
}