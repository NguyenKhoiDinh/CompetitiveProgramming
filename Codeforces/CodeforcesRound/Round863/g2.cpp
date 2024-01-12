#include <iostream> 
#include <math.h> 
const int mod = 1000000007; 
int dp[5005], ways[5005]; 
int n, k, numTest;
int a[5005]; 
int c[5005][5005]; 

int main () {
  for (int i = 0; i <= 5000; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod; 
    }
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      dp[i] = -1; 
      ways[i] = 0; 
    }
    dp[0] = 0; 
    ways[0] = 1;
    int maxLength = 0; 
    for (int i = 1; i <= n; i++) {
      int cnt = 0; 
      for (int j = i; j >= 1; j--) {
        if (a[j] == a[i]) {
          cnt++; 
        }
        if (cnt >= k) {
          dp[i] = std::max(dp[i], dp[j - 1] + 1); 
        }
      }
      maxLength = std::max(maxLength, dp[i]); 
      cnt = 0; 
      for (int j = i; j >= 1; j--) {
        if (a[j] == a[i]) {
          cnt++; 
        }
        if (cnt >= k && dp[j - 1] + 1 == dp[i]) {
          (ways[i] += (1LL * ways[j - 1] * c[cnt - 1][k - 1]) % mod) %= mod; 
        }    
      }
    }
    int ans = 0; 
    for (int i = 0; i <= n; i++) {
      if (maxLength == dp[i]) {
        (ans += ways[i]) %= mod; 
      }
    }
    std::cout << ans << std::endl; 
  }     
  return 0;
}