#include <iostream>

using namespace std;
const int MAX_N = 105;
const int MAX_VALUE = 100005;
const int inf = 1000000007;
struct object {
  int weight, value;
};
int dp[MAX_N][MAX_VALUE];
object a[MAX_N];
int n, W, sumValue = 0;

int main () {
  cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].weight >> a[i].value;
    sumValue += a[i].value;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sumValue; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int v = 0; v <= sumValue; v++) {
      if (dp[i][v] != inf) {
        dp[i + 1][v] = min(dp[i + 1][v], dp[i][v]);
        if (dp[i][v] + a[i + 1].weight <= W) {
          dp[i + 1][v + a[i + 1].value] = min(dp[i + 1][v + a[i + 1].value], dp[i][v] + a[i + 1].weight);
        }
      }
    }
  }
  int res = 0;
  for (int v = 0; v <= sumValue; v++) {
    if (dp[n][v] <= W) {
      res = v;
    }
  }
  cout << res;
  return 0;
}