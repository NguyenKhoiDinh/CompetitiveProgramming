#include <iostream>
#include <math.h>
const int mod = 123456789; 
int dp[2005][2005];
int ways[2005][2005]; 
int a[2005], b[2005];
int n, m; 

int main () {
  freopen("lcs.inp", "r", stdin);
  freopen("lcs.out", "w", stdout);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1; 
      }
      else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 || j == 1) {
        ways[i][j] = 1; 
      }
      else {
        if (a[i] == b[j]) {
          (ways[i][j] += ways[i - 1][j - 1]) %= mod; 
        }
        else {
          if (dp[i][j] == dp[i - 1][j]) {
            (ways[i][j] += ways[i - 1][j]) %= mod; 
          }
          if (dp[i][j] == dp[i][j - 1]) {
            (ways[i][j] += ways[i][j - 1]) %= mod; 
          }
          if (dp[i][j] == dp[i - 1][j - 1]) {
            ways[i][j] -= ways[i - 1][j - 1]; 
            (ways[i][j] += mod) %= mod; 
          }
        }
      }
    }
  }
  std::cout << dp[n][m] << ' ' << ways[n][m];
  return 0; 
}