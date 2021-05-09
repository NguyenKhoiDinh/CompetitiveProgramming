#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000000; 
const int MAX_N = 1000005; 
int dp[MAX_N][2], sum[MAX_N][2];

int main () {
  int n, k;
  cin >> n >> k;
  dp[0][0] = 1; 
  dp[0][1] = 1;
  dp[1][0] = 1; 
  dp[1][1] = 1;
  sum[1][0] = 1; 
  sum[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    int r = i - 1; 
    int l = max(0, i - k); 
    (dp[i][0] += ((sum[r][1] - sum[l][1] + dp[l][1]) % MOD + MOD) % MOD) %= MOD; 
    (dp[i][1] += ((sum[r][0] - sum[l][0] + dp[l][0]) % MOD + MOD) % MOD) %= MOD;
    sum[i][0] = (sum[i - 1][0] + dp[i][0]) % MOD; 
    sum[i][1] = (sum[i - 1][1] + dp[i][1]) % MOD; 
  }
  cout << (dp[n][0] + dp[n][1]) % MOD;
  return 0; 
}