#include <iostream>
#include <math.h>
int game[100005][3];
int dp[100005][3];
int n;

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> game[i][0] >> game[i][1] >> game[i][2];
  }
  for (int g = 0; g <= 2; g++) {
    dp[1][g] = game[1][g];
  }
  for (int i = 2; i <= n; i++) {
    for (int curGame = 0; curGame <= 2; curGame++) {
      for (int prevGame = 0; prevGame <= 2; prevGame++) {
        if (prevGame != curGame) {
          dp[i][curGame] = std::max(dp[i][curGame], dp[i - 1][prevGame] + game[i][curGame]);
        }
      }
    }
  }
  int res = -1;
  for (int lastGame = 0; lastGame <= 2; lastGame++) {
    res = std::max(res, dp[n][lastGame]);
  }
  std::cout << res;
  return 0;
}