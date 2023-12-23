#include <iostream> 
#include <algorithm>
const int mod = 1000000007; 
int a[12]; 
int n, m; 
int dp[12][1000005]; 

int main () {
  freopen("nequation.inp", "r", stdin);
  freopen("nequation.out", "w", stdout);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (n == 1) {
    std::cout << m / a[1]; 
  }
  else if (n == 2) {
    if (a[1] < a[2]) {
      std::swap(a[1], a[2]); 
    }
    if (a[1] == a[2]) {
      m /= a[1]; 
      long long ans = (long long) m; 
      ans *= (long long) (m - 1);
      ans /= 2; 
      ans %= mod;
      std::cout << ans;  
    }
    else {
      long long ans = 0LL; 
      for (int p = a[1]; p <= m; p += a[1]) {
        (ans += (m - p) / a[2]) %= mod; 
      }
      std::cout << ans; 
    }
  }
  else {
    dp[0][0] = 1LL; 
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (dp[i][j] == 0) {
          continue; 
        }
        if (i > 0 && j + a[i] <= m) {
          (dp[i][j + a[i]] += dp[i][j]) %= mod; 
        }
        if (i + 1 <= n && j + a[i + 1] <= m) {
          (dp[i + 1][j + a[i + 1]] += dp[i][j]) %= mod;
        }
      }  
    }
    long long ans = 0LL;
    for (int j = 1; j <= m; j++) {
      (ans += dp[n][j]) %= mod;
    }
    std::cout << ans; 
  }
  return 0; 
}