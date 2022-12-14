#include <iostream>
#include <math.h>
const long long inf = -2000000000000007LL;  
long long a[200005]; 
long long sum[200005];
long long dp[200005][2];
int n, k, numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      sum[i] = sum[i - 1] + a[i]; 
    } 
    for (int i = 0; i <= n; i++) {
      dp[i][0] = dp[i][1] = inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int state = 0; state <= 1; state++) {
        dp[i][state] = dp[i - 1][state];
        if (i >= k) {
          dp[i][state] = std::max(dp[i][state], dp[i - k][!state] + (long long) (state == 0 ? 1 : -1) * (sum[i] - sum[i - k])); 
        }  
      }  
    }
    long long ans = std::max(dp[n][0], dp[n][1]);
    for (int i = 0; i <= n; i++) {
      dp[i][0] = dp[i][1] = inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int state = 0; state <= 1; state++) {
        dp[i][state] = dp[i - 1][state];
        if (i >= k) {
          dp[i][state] = std::max(dp[i][state], dp[i - k][!state] + (long long) (state == 1 ? 1 : -1) * (sum[i] - sum[i - k])); 
        }  
      }  
    }
    ans = std::max(ans, std::max(dp[n][0], dp[n][1]));
    std::cout << ans << std::endl;
  }
  return 0; 
}