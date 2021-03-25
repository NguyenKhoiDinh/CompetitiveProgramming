#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;
const int MAX_N = 55;
int dp[MAX_N][MAX_N][MAX_N][MAX_N];

class VocaloidsAndSongs {
  public:
  int count(int S, int gumi, int ia, int mayu) {
    dp[0][0][0][0] = 1;
    for (int numSongs = 0; numSongs < S; numSongs++) {
      for (int a = 0; a <= gumi; a++) {
        for (int b = 0; b <= ia; b++) {
          for (int c = 0; c <= mayu; c++) {
            if (dp[numSongs][a][b][c] == 0) {
              continue;
            }
            int val = dp[numSongs][a][b][c];
            (dp[numSongs + 1][a + 1][b][c] += val) %= MOD;
            (dp[numSongs + 1][a][b + 1][c] += val) %= MOD;
            (dp[numSongs + 1][a][b][c + 1] += val) %= MOD;
            (dp[numSongs + 1][a + 1][b + 1][c] += val) %= MOD;
            (dp[numSongs + 1][a + 1][b][c + 1] += val) %= MOD;
            (dp[numSongs + 1][a][b + 1][c + 1] += val) %= MOD;
            (dp[numSongs + 1][a + 1][b + 1][c + 1] += val) %= MOD;
          }
        }
      }
    }
    return dp[S][gumi][ia][mayu];
  }
};

int main () {
  return 0;
}