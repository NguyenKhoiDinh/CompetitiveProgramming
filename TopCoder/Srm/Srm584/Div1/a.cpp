#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
const int inf = 10005;

int dist[MAX_N][MAX_N];

class Egalitarianism {
  public:
  int maxDifference(vector <string> isFriend, int d) {
    int n = (int) isFriend.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          dist[i][j] = 0;
        }
        else {
          dist[i][j] = inf;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isFriend[i][j] == 'Y') {
          dist[i][j] = 1;
        }
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(ans, dist[i][j]);
      }
    }
    return (ans == inf ? -1 : ans);
  }
};

int main () {
  return 0;
}