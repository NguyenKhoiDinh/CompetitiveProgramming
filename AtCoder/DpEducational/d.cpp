#include <bits/stdc++.h>

using namespace std;
struct object {
  int weight, value;
};
long long dp[105][100005];
object a[105];
int n, W;

int main () {
  cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].weight >> a[i].value;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      dp[i][j] = dp[i - 1][j];
      if (a[i].weight <= j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].weight] + a[i].value);
      }
    }
  }
  cout << dp[n][W];
  return 0;
}