#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 10005;
const int inf = -10000007;
int dp[MAX_N];
int n, k; 
int a[MAX_N];

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  int res = 0;
  dp[0] = 0; 
  for (int i = 1; i <= n; i++) {
    dp[i] = inf; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        dp[i] = max(dp[i], dp[i - j] + a[i]);
      }
    }
    if (res < dp[i]) {
      res = dp[i];
    }
  }
  cout << res;
  return 0; 
}