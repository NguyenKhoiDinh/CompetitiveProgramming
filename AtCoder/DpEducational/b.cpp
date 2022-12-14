#include <bits/stdc++.h> 

using namespace std;
long long dp[100005];
long long a[100005];
int n, k;

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = 1000000007;
  }
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= min(i - 1, k); j++) {
      dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
    }
  }
  cout << dp[n];
  return 0;
}