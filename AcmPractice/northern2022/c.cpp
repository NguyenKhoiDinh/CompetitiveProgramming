#include <iostream> 
#include <math.h>
#include <vector>
#include <set> 
#include <algorithm> 
int n; 
struct element {
  int x, y;
  bool operator < (const element &other) {
    return (x < other.x) || (x == other.x && y < other.y); 
  }
};
int dp[2005];
std::vector <element> save; 
int main () {
  while (std::cin >> n) {
    save.clear(); 
    for (int i = 1; i <= n; i++) {
      element e;
      std::cin >> e.x >> e.y;
      save.push_back(e);   
    }
    std::sort(save.begin(), save.end()); 
    for (int i = 1; i <= n; i++) {
      dp[i] = 0; 
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = 1;
      for (int j = 1; j <= i - 1; j++) {
        if (std::abs(save[i - 1].x - save[j - 1].x) + std::abs(save[i - 1].y - save[j - 1].y) >= 2) {
          dp[i] = std::max(dp[i], dp[j] + 1);   
        }
      }
    }                                
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = std::max(ans, dp[i]); 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}