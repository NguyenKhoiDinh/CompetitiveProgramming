#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 32;
const int inf = -1000000007;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N][MAX_N][4];
int sum[MAX_N][MAX_N];

int calc(int r1, int c1, int r2, int c2) {
  return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

class ThreeMines {
  public:
  int maximumProfit(vector <string> field) {
    int n = (int) field.size();
    int m = (int) field[0].size();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if ('a' <= field[i - 1][j - 1] && field[i - 1][j - 1] <= 'z') {
          a[i][j] = field[i - 1][j - 1] - 'a';
        }
        else {
          a[i][j] = 'A' - field[i - 1][j - 1];
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
      }
    }
    for (int r1 = 1; r1 <= n; r1++) {
      for (int r2 = 1; r2 <= n; r2++) {
        for (int c1 = 1; c1 <= m; c1++) {
          for (int c2 = 1; c2 <= m; c2++) {
            for (int cnt = 1; cnt <= 3; cnt++) {
              dp[r1][r2][c1][c2][cnt] = inf;
            }
          }
        }
      }
    }
    for (int cnt = 1; cnt <= 3; cnt++) {
      for (int r1 = n; r1 >= 1; r1--) {
        for (int r2 = r1; r2 <= n; r2++) {
          for (int c1 = m; c1 >= 1; c1--) {
            for (int c2 = c1; c2 <= m; c2++) {
              if (r1 < r2) {
                dp[r1][r2][c1][c2][cnt] = max(dp[r1][r2][c1][c2][cnt], dp[r1 + 1][r2][c1][c2][cnt]);
                dp[r1][r2][c1][c2][cnt] = max(dp[r1][r2][c1][c2][cnt], dp[r1][r2 - 1][c1][c2][cnt]);
              }
              if (c1 < c2) {
                dp[r1][r2][c1][c2][cnt] = max(dp[r1][r2][c1][c2][cnt], dp[r1][r2][c1 + 1][c2][cnt]);
                dp[r1][r2][c1][c2][cnt] = max(dp[r1][r2][c1][c2][cnt], dp[r1][r2][c1][c2 - 1][cnt]);
              }
              if (cnt == 1) {
                dp[r1][r2][c1][c2][1] = max(dp[r1][r2][c1][c2][1], calc(r1, c1, r2, c2));
              }
              else {
                for (int fi = 1; fi < cnt; fi++) {
                  int se = cnt - fi;
                  for (int rr = r1; rr < r2; rr++) {
                    if (dp[r1][rr][c1][c2][fi] == inf || dp[rr + 1][r2][c1][c2][se] == inf) {
                      continue;
                    }
                    int val = dp[r1][rr][c1][c2][fi];
                    val += dp[rr + 1][r2][c1][c2][se];
                    dp[r1][r2][c1][c2][cnt] = max(dp[r1][r2][c1][c2][cnt], val);
                  }
                  for (int cc = c1; cc < c2; cc++) {
                    if (dp[r1][r2][c1][cc][fi] == inf || dp[r1][r2][cc + 1][c2][se] == inf) {
                      continue;
                    }
                    int val = dp[r1][r2][c1][cc][fi];
                    val += dp[r1][r2][cc + 1][c2][se];
                    dp[r1][r2][c1][c2][cnt] = max(dp[r1][r2][c1][c2][cnt], val);
                  }
                }
              }
            }
          }
        }
      }
    }
    return dp[1][n][1][m][3];
  }
};

ThreeMines T;

int main () {
  cout << T.maximumProfit({
"bbbb",
"bBBB",
"BBbb",
"BBBB"});
  return 0;
}