#include <iostream>
#include <math.h> 
#include <cstring>
int n, sA, sB, numTest; 
int dp[15][15]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> sA >> sB; 
    std::memset(dp, 0, sizeof(dp)); 
    if (n > std::max(sA, sB)) {
      std::cout << 0 << std::endl;
      continue; 
    }                    
    if (std::abs(sA - sB) <= 1) {
      std::cout << 0 << std::endl;
      continue; 
    }
    dp[0][0] = 1; 
    for (int i = 0; i <= sA; i++) {
      for (int j = 0; j <= sB; j++) {
        if (dp[i][j] == 0) {
          continue; 
        }
        if ((i >= n || j >= n) && std::abs(i - j) >= 2) {
          continue; 
        }
        dp[i + 1][j] += dp[i][j];
        dp[i][j + 1] += dp[i][j];
      }
    }
    std::cout << dp[sA][sB] << std::endl;
  }
  return 0; 
}