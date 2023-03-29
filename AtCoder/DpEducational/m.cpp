#include <iostream>
#include <math.h>
const int mod = 1000000007; 
int dp[105][100005]; 
int sum[105][100005];
int n, k;
int a[105]; 

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  dp[0][0] = 1; 
  for (int j = 0; j <= k; j++) {
    sum[0][j] = 1; 
  } 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      int r = j; 
      int l = std::max(0, j - a[i]); 
      dp[i][j] = ((sum[i - 1][r] - sum[i - 1][l] + mod) % mod + dp[i - 1][l]) % mod; 
      sum[i][j] = (j > 0 ? (sum[i][j - 1] + dp[i][j]) % mod : dp[i][j]); 
    }
  }
  std::cout << dp[n][k];                
  return 0;
}