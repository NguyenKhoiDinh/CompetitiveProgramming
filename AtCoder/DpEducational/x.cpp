#include <iostream> 
#include <vector>
#include <math.h> 
#include <algorithm> 
struct rock {
  int weight, limit, cost;
  bool operator < (const rock &other) const {
    return weight + limit < other.weight + other.limit; 
  } 
};
std::vector <rock> listRocks; 
int n; 
long long dp[1005][20005]; 
                    
int main () {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    rock currentRock; 
    std::cin >> currentRock.weight >> currentRock.limit >> currentRock.cost; 
    listRocks.push_back(currentRock); 
  }
  std::sort(listRocks.begin(), listRocks.end()); 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 20000; j++) {
      dp[i][j] = -1; 
    }
  }
  dp[0][0] = 0; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 20000; j++) {
      if (dp[i][j] == -1) {
        continue; 
      }
      dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]); 
      if (j <= listRocks[i].limit) {
        dp[i + 1][j + listRocks[i].weight] = std::max(dp[i + 1][j + listRocks[i].weight], dp[i][j] + listRocks[i].cost); 
      }
    }
  }
  long long ans = -1; 
  for (int j = 0; j <= 20000; j++) {
    ans = std::max(ans, dp[n][j]); 
  }
  std::cout << ans; 
  return 0; 
}