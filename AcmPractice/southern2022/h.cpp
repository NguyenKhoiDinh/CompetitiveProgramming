#include <iostream> 
#include <string> 
#include <utility> 
#include <math.h>
const long long mod = 1000000007LL;
std::pair <double, long long> dp[100005][2][2]; 
std::string L, R; 

int main () {
  std::cin >> L >> R; 
  while ((int) L.size() < (int) R.size()) {
    L = "0" + L; 
  }
  int len = (int) L.size(); 
  dp[0][1][1] = std::make_pair(0.0, 1LL); 
  for (int i = 0; i < len; i++) {
    for (int bigger = 0; bigger <= 1; bigger++) {
      for (int smaller = 0; smaller <= 1; smaller++) {
        if (dp[i][bigger][smaller].second == 0) {
          continue; 
        }
        for (int dig = 1; dig <= 9; dig++) {
          if (bigger == 1 && dig < L[i] - '0') {
            continue; 
          }
          if (smaller == 1 && dig > R[i] - '0') {
            continue; 
          }
          int nextBigger = bigger;
          if (bigger == 1 && dig > L[i] - '0') {
            nextBigger = 0; 
          }
          int nextSmaller = smaller; 
          if (smaller == 1 && dig < R[i] - '0') {
            nextSmaller = 0; 
          }
          if (dp[i + 1][nextBigger][nextSmaller].first < dp[i][bigger][smaller].first + std::log(dig)) {
            dp[i + 1][nextBigger][nextSmaller] = std::make_pair(dp[i][bigger][smaller].first + std::log(dig), (dp[i][bigger][smaller].second * (long long) dig) % mod);   
          }
        }
      }
    }
  }
  long long ans = 0LL; 
  double maxi = -1.0; 
  for (int bigger = 0; bigger <= 1; bigger++) {
    for (int smaller = 0; smaller <= 1; smaller++) {
      if (maxi < dp[len][bigger][smaller].first) {
        maxi = dp[len][bigger][smaller].first; 
        ans = std::max(ans, dp[len][bigger][smaller].second); 
      }
    }
  }
  std::cout << ans;
  return 0; 
}