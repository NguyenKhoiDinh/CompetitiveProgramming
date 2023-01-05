#include <iostream>
#include <math.h> 
const long long inf = 10000000000007LL; 
int numTest; 
long long dp[405][405][2]; 
long long a[405]; 
int n;
long long D; 

long long value(int p1, int p2) {
  return std::min(std::abs(a[p1] - a[p2]), D - std::abs(a[p1] - a[p2])); 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cin >> n >> D;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    } 
    a[0] = 0; 
    a[n + 1] = 0;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        for (int state = 0; state <= 1; state++) {
          dp[i][j][state] = inf; 
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      dp[i][i][0] = value(i, i - 1); 
      dp[i][i][1] = value(i, i + 1); 
    }                       
    for (int i = n - 1; i >= 1; i--) {
      for (int j = i + 1; j <= n; j++) {
        dp[i][j][0] = std::min(dp[i + 1][j][0] + value(i, i - 1), dp[i][j - 1][1] + value(j, i - 1)); 
        dp[i][j][1] = std::min(dp[i + 1][j][0] + value(i, j + 1), dp[i][j - 1][1] + value(j, j + 1)); 
      }                                                                                
    }
    long long ans = std::min(dp[1][n][0], dp[1][n][1]); 
    std::cout << ans << std::endl; 
  }
  return 0; 
}