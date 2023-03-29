#include <iostream>
#include <math.h> 
int dp[100005];
int height[100005];
int n, k;

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> height[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = 1000000007;
  }
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= std::min(i - 1, k); j++) {
      dp[i] = std::min(dp[i], dp[i - j] + std::abs(height[i] - height[i - j]));
    }
  }
  std::cout << dp[n];
  return 0;
}