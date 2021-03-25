#include <iostream>

using namespace std;
const int MAX_N = 105;
const int MAX_W = 100005;
struct object {
  int weight, value;
};
long long dp[MAX_N][MAX_W];
object a[MAX_N];
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