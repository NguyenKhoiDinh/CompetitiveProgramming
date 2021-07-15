#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105; 
const int MAX_V = 100005; 
const int inf = 1000000007;
int n, S; 
int a[MAX_N];
int dp[MAX_N][MAX_V];

int main () {
  cin >> n >> S; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 0; 
  while (S > MAX_V) {
    S -= a[n];
    ans++;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i][j] = inf; 
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= a[i]) {
        dp[i][j] = min(dp[i][j], dp[i][j - a[i]] + 1);
      }
    }
  }
  cout << ans + dp[n][S];
  return 0; 
}