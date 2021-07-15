#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1005;
int dp[MAX_N][MAX_N];
int k;
string a, b;
int n;

int main () {
  cin >> k >> a >> b;
  n = (int) a.size();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1; 
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (dp[i][j] == -1) {
        continue;
      }
      if (a[i] == b[i]) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      else {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
      }
    }
  }
  cout << dp[n][k];
  return 0; 
}