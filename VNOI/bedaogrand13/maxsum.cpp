#include <iostream> 
#include <math.h> 
const long long inf = -100000000000007LL; 
long long dp[100005][3][2]; 
int n;
int a[100005]; 
long long ans = 0LL; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += a[i];  
  }
  if (n == 1) {
    std::cout << a[1]; 
    return 0; 
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 2; j++) {
      for (int state = 0; state <= 1; state++) {
        dp[i][j][state] = inf; 
      }
    }
  }
  dp[0][0][0] = 0LL; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2; j++) {
      for (int state = 0; state <= 1; state++) {
        if (dp[i][j][state] == inf) {
          continue; 
        }
        if (state == 0) {
          dp[i + 1][j][state] = std::max(dp[i + 1][j][state], dp[i][j][state] + a[i + 1]); 
          if (j < 2) {
            dp[i + 1][j + 1][1] = std::max(dp[i + 1][j + 1][1], dp[i][j][state] - a[i + 1]); 
          }
        }
        else {
          dp[i + 1][j][state] = std::max(dp[i + 1][j][state], dp[i][j][state] - a[i + 1]); 
          if (j < 2) {
            dp[i + 1][j + 1][1] = std::max(dp[i + 1][j + 1][1], dp[i][j][state] - a[i + 1]); 
          }
          dp[i + 1][j][0] = std::max(dp[i + 1][j][0], dp[i][j][state] + a[i + 1]); 
        }
      }
    }
  }
  for (int j = 0; j <= 2; j++) {
    ans = std::max(ans, dp[n][j][0]);
    ans = std::max(ans, dp[n][j][1]);
  }
  std::cout << ans; 
  return 0;
}