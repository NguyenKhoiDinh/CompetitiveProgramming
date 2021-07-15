#include <bits/stdc++.h>

using namespace std;
const int MAX_H = 42;
const int MAX_W = 9;
int dp[MAX_H][MAX_W][(1 << 7) + 5];
int ways[MAX_H][MAX_W][(1 << 7) + 5];
bool mark[MAX_H][MAX_W][(1 << 7) + 5];

void update(int &a, int b, int MOD) {
  (a += b) %= MOD;
}

class BearDestroysDiv2 {
  public:
  int sumUp(int W, int H, int MOD) {
    ways[1][1][0] = 1;
    dp[1][1][0] = 0;
    mark[1][1][0] = true;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        for (int mask = 0; mask < (1 << W); mask++) {
          if (mark[i][j][mask] == false) {
            continue;
          }
          int nxti = i;
          int nxtj = j;
          nxtj++;
          if (nxtj > W) {
            nxti++;
            nxtj = 1;
          }
          int curWays = ways[i][j][mask];
          if ((mask & 1) == 0) {
            //South
            int nxtMask = mask >> 1;
            int fallDown = 0;
            if (i < H) {
              nxtMask += (1 << (W - 1));
              fallDown = 1;
            }
            else if (j < W && ((nxtMask & 1) == 0)) {
              nxtMask++;
              fallDown = 1;
            }
            update(dp[nxti][nxtj][nxtMask], (dp[i][j][mask] + fallDown * curWays) % MOD, MOD);
            update(ways[nxti][nxtj][nxtMask], curWays, MOD);
            mark[nxti][nxtj][nxtMask] = true;
            //East
            nxtMask = mask >> 1;
            fallDown = 0;
            if (j < W && ((nxtMask & 1) == 0)) {
              nxtMask++;
              fallDown = 1;
            }
            else if (i < H) {
              nxtMask += (1 << (W - 1));
              fallDown = 1;
            }
            update(dp[nxti][nxtj][nxtMask], (dp[i][j][mask] + fallDown * curWays) % MOD, MOD);
            update(ways[nxti][nxtj][nxtMask], curWays, MOD);
            mark[nxti][nxtj][nxtMask] = true;
          }
          else {
            int nxtMask = mask >> 1;
            update(dp[nxti][nxtj][nxtMask], (2 * dp[i][j][mask]) % MOD, MOD);
            update(ways[nxti][nxtj][nxtMask], (2 * curWays) % MOD, MOD);
            mark[nxti][nxtj][nxtMask] = true;
          }
        }
      }
    }
    return dp[H + 1][1][0];
  }
};
BearDestroysDiv2 B;

int main () {
  cout << B.sumUp(2,
3,
1000000007);
  return 0;
}