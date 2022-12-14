#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 5000005;
long long dp[MAX_N];
long long sum[MAX_N];
int n; 
long long MOD;

int main () {
  cin >> n >> MOD;
  dp[n] = 1;
  sum[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = sum[i + 1];
    for (int j = 2; j <= n / i; j++) {
      int r = min(i * j + j - 1, n);
      int l = i * j;
      (dp[i] += (sum[l] - sum[r + 1] + MOD) % MOD) %= MOD;  
    }
    sum[i] = (sum[i + 1] + dp[i]) % MOD;
  }
  cout << dp[1];
  return 0; 
}