#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 100005;
int game[MAX_N][3];
int dp[MAX_N][3];
int n;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> game[i][0] >> game[i][1] >> game[i][2];
  }
  for (int g = 0; g <= 2; g++) {
    dp[1][g] = game[1][g];
  }
  for (int i = 2; i <= n; i++) {
    for (int curGame = 0; curGame <= 2; curGame++) {
      for (int prevGame = 0; prevGame <= 2; prevGame++) {
        if (prevGame != curGame) {
          dp[i][curGame] = max(dp[i][curGame], dp[i - 1][prevGame] + game[i][curGame]);
        }
      }
    }
  }
  int res = -1;
  for (int lastGame = 0; lastGame <= 2; lastGame++) {
    res = max(res, dp[n][lastGame]);
  }
  cout << res;
  return 0;
}