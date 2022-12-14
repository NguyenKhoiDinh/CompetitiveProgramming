#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 30;
const int MOD = 1000000007;
int dp[MAX_N][MAX_N][MAX_N][3];

class AnnoyingPasswords {
  public:
  int count(int U, int L, int D) {
    if (U == 0 && L == 0 && D == 0) {
      return 1;
    }
    if (U > 0) {
      dp[1][0][0][0] = 26;
    }  
    if (L > 0) {
      dp[0][1][0][1] = 26;
    }
    if (D > 0) {
      dp[0][0][1][2] = 10;
    }
    for (int u = 0; u <= U; u++) {
      for (int l = 0; l <= L; l++) {
        for (int d = 0; d <= D; d++) {
          for (int type = 0; type <= 2; type++) {
            if (dp[u][l][d][type] == 0) {
              continue;
            }
            if (u < U && type != 0) {
              (dp[u + 1][l][d][0] += (1LL * dp[u][l][d][type] * (26 - u)) % MOD) %= MOD;
            }
            if (l < L && type != 1) {
              (dp[u][l + 1][d][1] += (1LL * dp[u][l][d][type] * (26 - l)) % MOD) %= MOD;
            }
            if (d < D && type != 2) {
              (dp[u][l][d + 1][2] += (1LL * dp[u][l][d][type] * (10 - d)) % MOD) %= MOD;
            }
          }  
        }
      }
    }
    int ans = 0;
    for (int type = 0; type <= 2; type++) {
      (ans += dp[U][L][D][type]) %= MOD;
    }
    return ans;
  }
};

int main () {
  return 0;
}