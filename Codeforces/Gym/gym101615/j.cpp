#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 33;
long long dp[MAX_N][MAX_N];
char a[MAX_N][MAX_N];
int n, m;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][m] = 1LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      if (dp[i][j] == 0) {
        continue;
      }
      long long val = dp[i][j];
      int maxBlue = -1;
      int minRed = -1;
      for (int y = 1; y <= m; y++) {
        if (a[i + 1][y] == 'B') {
          maxBlue = y;
        }
      }
      for (int y = m; y >= 1; y--) {
        if (a[i + 1][y] == 'R') {
          minRed = y;
        }
      }
      if (maxBlue == -1) {
        for (int y = 0; y <= min(j, minRed == -1 ? m : minRed - 1); y++) {
          dp[i + 1][y] += val;
        }
      }
      else {
        if (minRed == -1) {
          if (maxBlue <= j) {
            for (int y = maxBlue; y <= j; y++) {
              dp[i + 1][y] += val;
            }
          }
        }
        else {
          if (minRed > maxBlue) {
            if (maxBlue <= j) {
              dp[i + 1][maxBlue] += val;
              for (int y = maxBlue + 1; y <= min(minRed - 1, j); y++) {
                dp[i + 1][y] += val;
              }
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= m; j++) {
    ans += dp[n][j];
  }
  cout << ans;
  return 0;
}