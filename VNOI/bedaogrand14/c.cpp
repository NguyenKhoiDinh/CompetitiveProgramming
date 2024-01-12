#include <iostream>
const int mod = 1000000007; 
int dp[3005][3005][2]; 
int a0, a1, b0, b1; 

int main () {
  std::cin >> a0 >> a1;
  std::cin >> b0 >> b1;
  for (int i = b0; i <= a0; i++) {
    dp[i][0][0] = 1; 
  }
  for (int i = b1; i <= a1; i++) {
    dp[0][i][1] = 1;  
  }
  for (int i = 0; i <= a0; i++) {
    for (int j = 0; j <= a1; j++) {
      if (i >= b0) {
        for (int x = b0; x <= i; x++) {
          (dp[i][j][0] += dp[i - x][j][1]) %= mod; 
        }
      }                                                     
      if (j >= b1) {
        for (int x = b1; x <= j; x++) {
          (dp[i][j][1] += dp[i][j - x][0]) %= mod;
        }
      }
    }
  }
  int ans = 0LL;
  for (int i = b0; i <= a0; i++) {
    for (int j = b1; j <= a1; j++) {
      (ans += dp[i][j][0]) %= mod;
      (ans += dp[i][j][1]) %= mod;
    }  
  }
  std::cout << ans;
  return 0; 
}