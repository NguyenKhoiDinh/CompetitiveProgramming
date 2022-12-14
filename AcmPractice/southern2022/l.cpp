#include <iostream> 
#include <string>
#include <algorithm>
#include <math.h>  
int numTest;
std::string a, b, res; 
int dp[1005][2]; 
int n; 

int main () {
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }
    std::cin >> a >> b >> res;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    std::reverse(res.begin(), res.end());
    for (int i = 0; i <= n; i++) {
      dp[i][0] = -1;
      dp[i][1] = -1; 
    }  
    dp[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int rem = 0; rem <= 1; rem++) {
        if (dp[i][rem] == -1) {
          continue; 
        }
        dp[i + 1][rem] = std::max(dp[i + 1][rem], dp[i][rem]); 
        int total = (a[i] - '0' + b[i] - '0' + rem) % 10; 
        if (total == res[i] - '0') {
          int nextRem = (a[i] - '0' + b[i] - '0' + rem) / 10; 
          dp[i + 1][nextRem] = std::max(dp[i + 1][nextRem], dp[i][rem] + 1); 
        } 
      }
    }
    std::cout << n - dp[n][0] << std::endl; 
  }
  return 0; 
}