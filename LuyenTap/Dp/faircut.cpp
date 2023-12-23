#include <iostream>
#include <algorithm>
#include <math.h>         
const long long inf = 100000000000007LL; 
int n, k; 
long long dp[3005][3005]; 
int a[3005]; 

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + n + 1); 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = inf; 
    }
  }
  dp[1][1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      if (dp[i][j] == inf) {
        continue; 
      }
      dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + (long long) j * (a[i + 1] - a[i])); 
      dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + (long long) j * (a[i + 1] - a[i])); 
    }
  }
  std::cout << std::min(dp[n][k], dp[n][n - k]); 
  return 0; 
}