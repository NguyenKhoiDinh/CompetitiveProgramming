#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 70; 
unsigned long long dp[MAX_N][MAX_N];
int n, m;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  for (int i = 1; i < MAX_N; i++) {
    dp[i][3] = (unsigned long long) (1LL << i) - 1; 
  }
  for (int j = 4; j < MAX_N; j++) {
    for (int i = 1; i < MAX_N; i++) {
      if (i < j) {
        dp[i][j] = 2 * i - 1;
        continue; 
      }
      if (i == j) {
        dp[i][j] = 2 * i + 1; 
        continue;
      }
      dp[i][j] = LONG_LONG_MAX;
      for (int x = 1; x < i; x++) {
        dp[i][j] = min(dp[i][j], 2LL * dp[x][j] + dp[i - x][j - 1]);
      }
    }
  }
  while (cin >> n >> m) {
    cout << dp[n][m] << endl;
  }
  return 0; 
}