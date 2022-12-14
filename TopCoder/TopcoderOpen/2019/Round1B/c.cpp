#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 55;
const int MAX_C = 15;
const int inf = 10000007;
int dp[MAX_N][(1 << MAX_C) + 5][MAX_C + 3];

void updateMin(int &a, int b) {
  if (a > b) {
    a = b;
  }
}

class EllysPearls {
  public:
  int getMin(int N, int M, vector <int> pearls) {
    for (int i = 0; i < N; i++) {
      pearls[i]--;
    }
    int totalMask = 0;
    for (int i = 0; i < N; i++) {
      totalMask |= (1 << pearls[i]);
    }
    for (int i = 0; i <= N; i++) {
      for (int mask = 0; mask < (1 << M); mask++) {
        for (int lastColor = 0; lastColor <= M; lastColor++) {
          dp[i][mask][lastColor] = inf;
        }
      }
    }
    dp[0][0][M] = 0;
    for (int i = 0; i <= N; i++) {
      for (int mask = 0; mask < (1 << M); mask++) {
        for (int lastColor = 0; lastColor <= M; lastColor++) {
          if (dp[i][mask][lastColor] == inf) {
            continue;
          }
          int curVal = dp[i][mask][lastColor];
          if (lastColor == pearls[i]) {
            updateMin(dp[i + 1][mask][lastColor], curVal);
          }
          else {
            updateMin(dp[i + 1][mask][lastColor], curVal + 1);
            if ((mask & (1 << pearls[i])) == 0) {
              updateMin(dp[i + 1][mask | (1 << pearls[i])][pearls[i]], curVal);
            }
          }
        }
      }
    }
    int res = inf;
    for (int lastColor = 0; lastColor < M; lastColor++) {
      for (int mask = 0; mask < (1 << M); mask++) {
        updateMin(res, dp[N][mask][lastColor]);
      }
    }
    return res;
  }
};

EllysPearls E;

int main () {
  cout << E.getMin(48, 11, {1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
  3, 4, 1, 9, 9, 9, 4, 1, 1, 4, 6, 1, 11, 1, 1, 8, 4, 1, 1, 5, 1,
  1, 1, 10, 10, 1, 11, 1, 10, 1, 5, 1, 7, 1, 2, 4, 1});
  return 0;
}