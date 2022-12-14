#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005; 
int a[MAX_N];
int n, k; 
int dp[MAX_N][55]; 

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= k;
  }
  for (int i = 0; i <= n; i++) {
    for (int r = 0; r < k; r++) {
      dp[i][r] = -1; 
    }
  }
  dp[0][0] = 0; 
  for (int i = 0; i < n; i++) {
    for (int r = 0; r < k; r++) {
      if (dp[i][r] == -1) {
        continue; 
      }
      dp[i + 1][r] = max(dp[i + 1][r], dp[i][r]); 
      dp[i + 1][(r + a[i + 1]) % k] = max(dp[i + 1][(r + a[i + 1]) % k], dp[i][r] + 1);
    }
  }
  cout << dp[n][0];
  return 0; 
}