#include <iostream> 
#include <math.h> 
int n;
int height[100005];
int dp[100005]; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> height[i]; 
  }
  dp[1] = 0; 
  dp[2] = std::abs(height[2] - height[1]); 
  for (int i = 3; i <= n; i++) {
    dp[i] = std::min(dp[i - 1] + std::abs(height[i] - height[i - 1]), dp[i - 2] + std::abs(height[i] - height[i - 2])); 
  }
  std::cout << dp[n];
  return 0;
}