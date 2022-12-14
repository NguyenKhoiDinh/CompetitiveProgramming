#include <iostream>
#include <string>  
int dp[305][305][305];
int sum[305];
std::string s;        
int n, k; 

int main () {
  std::cin >> n >> k;
  std::cin >> s;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1]; 
    if (s[i - 1] == 'B') {
      sum[i]++;
    }
  } 
  for (int i = n; i >= 1; i--) {
    for (int j = i; j <= n; j++) {
      for (int x = 0; x <= std::min(k, sum[n] - (sum[j] - sum[i - 1])); x++) {
        int rest = sum[n] - (sum[j] - sum[i - 1]) - x; 
        if ((s[i - 1] == 'W' || (s[i - 1] == 'B' && x < k - 1)) && dp[i + 1][j][rest] == 0) {
          dp[i][j][x] = 1; 
        }
        if ((s[j - 1] == 'W' || (s[j - 1] == 'B' && x < k - 1)) && dp[i][j - 1][rest] == 0) {
          dp[i][j][x] = 1; 
        }
      }
    }
  }  
  if (dp[1][n][0] == 1) {
    std::cout << "YES"; 
  }
  else {
    std::cout << "NO"; 
  }
  return 0; 
}