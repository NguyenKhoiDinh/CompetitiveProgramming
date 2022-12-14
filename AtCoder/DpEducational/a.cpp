#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
const int MAX_N = 100005;
const int inf = 1000000007;
int dp[MAX_N];
int height[MAX_N];
int n;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = inf;
  }
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (i >= 2) {
      dp[i] = min(dp[i], dp[i - 1] + abs(height[i] - height[i - 1]));
    }
    if (i >= 3) {
      dp[i] = min(dp[i], dp[i - 2] + abs(height[i] - height[i - 2]));
    }
  }
  cout << dp[n];
  return 0;
}