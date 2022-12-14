#include <bits/stdc++.h>

using namespace std;
const int MAX_W = 9;
const int MAX_H = 42;
int dp[MAX_W][MAX_H][MAX_W * MAX_H][(1 << 7) + 5];

void update(int &a, int b, int MOD) {
  (a += b) %= MOD;
}

class BearDestroysDiv2 {
  public:
  int sumUp(int W, int H, int MOD) {
    dp[1][1][0][0] = 1;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        for (int numTree = 0; numTree <= (W * H) / 2; numTree++) {
          for (int mask = 0; mask < (1 << W); mask++) {
            if (dp[i][j][numTree][mask] == 0) {
              continue;
            }
            int val = dp[i][j][numTree][mask];
            int nxti = i, nxtj = j;
            nxtj++;
            if (nxtj > W) {
              nxtj = 1;
              nxti++;
            }
            if ((mask & 1) == 0) {
              //South
              int nxtMask = mask >> 1;
              int nxtTree = numTree;
              if (i < H) {
                nxtMask += (1 << (W - 1));
                nxtTree++;
              }
              else if (j < W && ((nxtMask & 1) == 0)) {
                nxtMask++;
                nxtTree++;
              }
              update(dp[nxti][nxtj][nxtTree][nxtMask], val, MOD);
              //East
              nxtMask = mask >> 1;
              nxtTree = numTree;
              if (j < W && ((nxtMask & 1) == 0)) {
                nxtMask++;
                nxtTree++;
              }
              else if (i < H) {
                nxtMask += (1 << (W - 1));
                nxtTree++;
              }
              update(dp[nxti][nxtj][nxtTree][nxtMask], val, MOD);
            }
            else {
              int nxtMask = mask >> 1;
              update(dp[nxti][nxtj][numTree][nxtMask], (2 * val) % MOD, MOD);
            }
          }
        }
      }
    }
    int ans = 0;
    for (int numTree = 1; numTree <= W * H; numTree++) {
      ans += (1LL * numTree * dp[H + 1][1][numTree][0]) % MOD;
      ans %= MOD;
    }
    return ans;
  }
};

BearDestroysDiv2 B;

int main () {
  cout << B.sumUp(4,
3,
999999937);
  return 0;
}