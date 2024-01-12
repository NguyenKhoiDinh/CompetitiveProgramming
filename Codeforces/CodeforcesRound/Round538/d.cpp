#include <iostream> 
#include <vector> 
int n; 
int a[5005]; 
std::vector <int> components; 
int dp[5005][5005];

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  components.push_back(a[1]); 
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      components.push_back(a[i]); 
    }
  }
  n = (int) components.size(); 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 5000; j++) {
      dp[i][j] = n + 10; 
    }
  }
  dp[1][components[0]] = 0; 
  for (int i = 1; i < n; i++) {
    for (int color = 0; color <= n; color++) {
      if (dp[i][color] == n + 10) {
        continue; 
      }
      for (int nextColor = 0; nextColor <= n; nextColor++) {
        if (nextColor == components[i] && color == nextColor) {
          dp[i + 1][nextColor] = std::min(dp[i + 1][nextColor], dp[i][color]); 
        }
        else {
          dp[i + 1][nextColor] = std::min(dp[i + 1][nextColor], dp[i][color] + 1); 
        }
      }
    }
  }
  int ans = n + 10; 
  for (int j = 0; j <= 5000; j++) {
    ans = std::min(ans, dp[n][j]);
  }
  std::cout << ans;
  return 0; 
}