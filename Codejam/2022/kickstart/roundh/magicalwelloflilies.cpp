#include <iostream> 
#include <math.h> 
int numTest; 
const int inf = 1000000007; 
int dp[100005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      dp[i] = inf; 
    } 
    dp[1] = 1; 
    for (int i = 1; i <= n; i++) {
      if (dp[i] != inf) {
        dp[i + 1] = std::min(dp[i + 1], dp[i] + 1); 
        for (int j = i + i; j <= n; j += i) {
          dp[j] = std::min(dp[j], dp[i] + 4 + 2 * (j / i - 1)); 
        }
      }
    }
    std::cout << dp[n] << std::endl;
  }
  return 0; 
}