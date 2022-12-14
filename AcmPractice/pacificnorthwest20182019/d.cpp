#include <bits/stdc++.h> 

using namespace std;
const int MOD = 1000000009;
const int MAX_N = 150;
const int MAX_K = 1005;
int dp[MAX_N][MAX_N][MAX_K];
int k, b;

int main () {
  cin >> k >> b;
  dp[0][0][0] = 1;
  for (int i = 0; i < b; i++) {
    for (int one = 0; one <= i; one++) {
      for (int r = 0; r < k; r++) {
        if (dp[i][one][r] == 0) {
          continue;
        }
        (dp[i + 1][one][(r * 2) % k] += dp[i][one][r]) %= MOD;
        (dp[i + 1][one + 1][(r * 2 + 1) % k] += dp[i][one][r]) %= MOD;
      }
    }
  }
  long long ans = 0LL;
  for (int one = 1; one <= b; one++) {
    (ans += (1LL * one * dp[b][one][0]) % MOD) %= MOD;
  }
  cout << ans;
  return 0; 
}