#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
const int MAX_N = 100005;
const int inf = 1000000007;
int dp[MAX_N];
int height[MAX_N];
int n, k;

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = inf;
  }
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= min(i - 1, k); j++) {
      dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
    }
  }
  cout << dp[n];
  return 0;
}