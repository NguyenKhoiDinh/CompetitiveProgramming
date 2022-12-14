#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 3005;
const long long MOD = 1000000007;
long long dp[MAX_N][MAX_N];

class PalindromicSubseq2 {
  public:
  int solve(string s) {
    int n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = n; j >= i; j--) {
        (dp[i][j] += dp[i - 1][j]) %= MOD;
        (dp[i][j] += dp[i][j + 1]) %= MOD;
        if (s[i - 1] != s[j - 1]) {
          (dp[i][j] += (MOD - dp[i - 1][j + 1]) % MOD) %= MOD;
        }
      }
    }
    long long ans = 0LL;
    for (int i = 1; i <= n; i++) {
      long long mul = (dp[i - 1][i + 1] + 1) % MOD;
      (mul *= 1LL * i) %= MOD;
      ans ^= mul;
    }
    return (int) ans;
  }
};

PalindromicSubseq2 P;

int main () {
  cout << P.solve("axbcba");
  return 0;
}

/*
axbcba
*/