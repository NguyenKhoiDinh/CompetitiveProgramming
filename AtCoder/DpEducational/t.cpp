#include <iostream>
#include <string> 
const int mod = 1000000007; 
int dp[3005][3005];
int sum[3005][3005]; 
std::string s; 
int n;

int main () {
  std::cin >> n;
  std::cin >> s;                  
  dp[1][1] = 1;
  sum[1][1] = 1; 
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (s[i - 2] == '<') {
        dp[i][j] = sum[i - 1][j - 1]; 
      }
      else {
        dp[i][j] = (sum[i - 1][i - 1] - sum[i - 1][j - 1] + mod) % mod; 
      }
      sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
    }
  }
  int ans = 0;
  for (int j = 1; j <= n; j++) {
    (ans += dp[n][j]) %= mod; 
  } 
  std::cout << ans;
  return 0;
}