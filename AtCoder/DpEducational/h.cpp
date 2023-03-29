#include <iostream>
#include <string>
const int mod = 1000000007; 
int dp[1005][1005]; 
std::string a[1005]; 
int H, W; 

int main () {
  std::cin >> H >> W; 
  for (int i = 0; i < H; i++) {
    std::cin >> a[i]; 
  }
  dp[1][1] = 1; 
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (dp[i][j] == 0) {
        continue; 
      }
      if (i < H && a[i][j - 1] == '.') {
        (dp[i + 1][j] += dp[i][j]) %= mod; 
      }
      if (j < W && a[i - 1][j] == '.') {
        (dp[i][j + 1] += dp[i][j]) %= mod; 
      }
    }
  }
  std::cout << dp[H][W]; 
  return 0;
}