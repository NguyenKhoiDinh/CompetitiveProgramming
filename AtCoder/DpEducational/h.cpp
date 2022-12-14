#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007; 
int dp[1005][1005]; 
string a[1005]; 
int H, W; 

int main () {
  cin >> H >> W; 
  for (int i = 0; i < H; i++) {
    cin >> a[i]; 
  }
  dp[1][1] = 1; 
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (dp[i][j] == 0) {
        continue; 
      }
      if (i < H && a[i][j - 1] == '.') {
        (dp[i + 1][j] += dp[i][j]) %= MOD; 
      }
      if (j < W && a[i - 1][j] == '.') {
        (dp[i][j + 1] += dp[i][j]) %= MOD; 
      }
    }
  }
  cout << dp[H][W]; 
  return 0;
}