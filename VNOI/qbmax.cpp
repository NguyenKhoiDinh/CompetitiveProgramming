#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105;
int n, m;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main () {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][1] = a[i][1]; 
  }
  for (int j = 2; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      dp[i][j] = dp[i][j - 1] + a[i][j];
      if (i > 1) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]); 
      }
      if (i < n) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
      }
    }
  }
  int res = -100007; 
  for (int i = 1; i <= n; i++) {
    res = max(res, dp[i][m]); 
  }
  cout << res;
  return 0; 
}