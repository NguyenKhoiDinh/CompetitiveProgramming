#include <iostream> 
#include <algorithm>
const int mod = 1000000009;
int dp[1005][1005][12];
int a[1005];
int b[1005];
int n, m, k; 

int main () {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + n + 1); 
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::sort(b + 1, b + m + 1); 
  dp[0][0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int selected = 0; selected <= k; selected++) {
        if (dp[i][j][selected] == 0) {
          continue; 
        }
        if (i < n) {
          (dp[i + 1][j][selected] += dp[i][j][selected]) %= mod;
        }
        if (j < m) {
          (dp[i][j + 1][selected] += dp[i][j][selected]) %= mod;
        }
        if (i < n && j < m) {
          dp[i + 1][j + 1][selected] -= dp[i][j][selected];
          (dp[i + 1][j + 1][selected] += mod) %= mod;
        }
        if (i < n && j < m && selected < k && a[i + 1] > b[j + 1]) {
          (dp[i + 1][j + 1][selected + 1] += dp[i][j][selected]) %= mod;   
        }
      }
    }
  }
  std::cout << dp[n][m][k]; 
  return 0; 
}