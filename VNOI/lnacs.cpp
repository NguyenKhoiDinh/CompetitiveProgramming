#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005; 
int dp[MAX_N][MAX_N];
int a[MAX_N], b[MAX_N];
int n, m;

int main () {
  cin >> n >> m; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = (i >= 2 && j >= 2 ? dp[i - 2][j - 2] + 1: 1);
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[n][m];
  return 0; 
}