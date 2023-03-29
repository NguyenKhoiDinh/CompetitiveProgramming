#include <iostream> 
int n, k; 
int dp[100005]; 
int a[105]; 

int main () {
  std::cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  dp[0] = 0; 
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= a[j] && dp[i - a[j]] == 0) {
        dp[i] = 1; 
      }
    }
  }
  std::cout << (dp[k] == 1 ? "First" : "Second"); 
  return 0; 
}