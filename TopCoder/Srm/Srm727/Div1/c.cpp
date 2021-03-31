#include <bits/stdc++.h>

using namespace std;
const long long MAX_SHOOT = 6005;
const int MAX_N = 2005; 
const long long MOD = 1000000007;
long long dp[MAX_N][2 * MAX_N][2];
long long inv[3 * MAX_N];

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long tmp = POW(x, n >> 1);
  (tmp *= tmp) %= MOD;
  if (n & 1) {
    (tmp *= x) %= MOD;
  }
  return tmp;
}

class DoubleLive {
  public:
  int findEV(int B, int H, int T) {
    for (int i = 1; i < 3 * MAX_N; i++) {
      inv[i] = POW(i, MOD - 2);
    }
    long long ans = 0LL;
    dp[B][H][0] = 1LL;
    for (int two = B; two >= 0; two--) {
      for (int one = B + H; one >= 1; one--) {
        for (int isShot = 0; isShot <= 1; isShot++) {
          if (dp[two][one][isShot] == 0) {
            continue;
          }
          if (2 * B + H - 2 * two - one == T) {
            (ans += (dp[two][one][isShot] * (two + one)) % MOD) %= MOD;
            continue;
          }
          long long curValue = (dp[two][one][isShot] * inv[two + one]) % MOD;
          if (isShot == 0) {
            if (one >= 1) {
              (dp[two][one - 1][0] += (curValue * (one - 1)) % MOD) %= MOD;
            }
            if (two >= 1) {
              (dp[two - 1][one + 1][0] += (curValue * (two - 1)) % MOD) %= MOD;
              (dp[two - 1][one + 1][1] += curValue) %= MOD;
            }
          }
          else {
            if (two >= 1) {
              (dp[two - 1][one + 1][1] += (curValue * two) % MOD) %= MOD;
            }
            if (one >= 2) {
              (dp[two][one - 1][1] += (curValue * (one - 2)) % MOD) %= MOD;
            }
          }
        }
      }
    }
    (ans *= B) %= MOD;
    (ans *= H) %= MOD;
    return ans;
  }
};

int main () {
  return 0;
}