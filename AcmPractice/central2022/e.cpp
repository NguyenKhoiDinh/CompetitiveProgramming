#include <iostream> 
#include <algorithm> 
const int mod = 1000000007; 
int dp[105][105][12];
int n, R, C; 
int p[12];
int a[105][105]; 
int sum[105][105]; 

int sumSub(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]; 
}
             
int main () {
  std::cin >> R >> C >> n;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      std::cin >> a[i][j]; 
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j]; 
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  std::reverse(p + 1, p + n + 1); 
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      int x2 = R; 
      int y2 = C; 
      int x1 = R - i + 1; 
      int y1 = C - j + 1;
      if (sumSub(x1, y1, x2, y2) <= p[1]) {
        dp[i][j][1] = 1; 
      }
    }
  }
  for (int numb = 1; numb < n; numb++) {
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (dp[i][j][numb] == 0) {
          continue; 
        }  
        for (int x = 1; x + i <= R; x++) {
          int x2 = R - i; 
          int y2 = C; 
          int x1 = R - i - x + 1; 
          int y1 = C - j + 1; 
          if (sumSub(x1, y1, x2, y2) <= p[numb + 1]) {
            (dp[i + x][j][numb + 1] += dp[i][j][numb]) %= mod; 
          }
        }
        for (int x = 1; x + j <= C; x++) {
          int x2 = R; 
          int y2 = C - j;
          int x1 = R - i + 1; 
          int y1 = C - j - x + 1; 
          if (sumSub(x1, y1, x2, y2) <= p[numb + 1]) {
            (dp[i][j + x][numb + 1] += dp[i][j][numb]) %= mod; 
          }
        }
      }
    }
  }
  std::cout << dp[R][C][n]; 
  return 0; 
}                   