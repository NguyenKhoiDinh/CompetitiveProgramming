#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 205;
const long long MOD = 1000000007;
long long dp[MAX_N][MAX_N][MAX_N];

void update(long long a, long long b) {
  (a += b) %= MOD; 
}

class BearCries {
  public:
  int count(string message) {
    int n = (int) message.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int openComma = 0; openComma <= i; openComma++) {
        for (int openMouth = 0; openMouth <= i - openComma; openMouth++) {
          if (dp[i][openComma][openMouth] == 0) {
            continue;
          }
          long long cur = dp[i][openComma][openMouth];
          if (message[i] == ';') {
            update(dp[i + 1][openComma + 1][openMouth], cur);
            if (openMouth > 0) {
              update(dp[i + 1][openComma][openMouth - 1], (1LL * cur * openMouth) % MOD);
            }
          }
          else {
            if (openComma > 0) {
              update(dp[i + 1][openComma - 1][openMouth + 1], (1LL * cur * openComma) % MOD);
            }
            if (openMouth > 0) {
              update(dp[i + 1][openComma][openMouth], (1LL * cur * openMouth) % MOD);
            }
          }
        }
      }
    }
    return (int) dp[n][0][0];
  }
};

int main () {
  return 0;
}