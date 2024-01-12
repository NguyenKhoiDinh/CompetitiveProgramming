#include <iostream> 
#include <unordered_map>
#include <math.h> 
const long long mod = 998244353; 
int a[305];
int n; 
int S = 0; 
long long dp[305][90005]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    S += a[i];  
  } 
  dp[0][0] = 1LL; 
  for (int i = 0; i < n; i++) {
    for (int sum = 0; sum <= S; sum++) {
      if (dp[i][sum] == 0) {
        continue; 
      }
      (dp[i + 1][sum] += dp[i][sum]) %= mod;
      (dp[i + 1][sum + a[i + 1]] += (2LL * dp[i][sum]) % mod) %= mod; 
    }
  }
  long long ans = 1LL;
  for (int i = 1; i <= n; i++) {
    (ans *= 3LL) %= mod; 
  }                             
  for (int sum = 0; sum <= S / 2; sum++) {
    std::cout << sum << "    " << dp[n][sum] << std::endl;
    ans -= (3LL * dp[n][sum]) % mod; 
    (ans += mod) %= mod; 
  }
  std::cout << ans; 
  return 0; 
}