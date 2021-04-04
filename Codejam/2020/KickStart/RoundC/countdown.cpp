#include <bits/stdc++.h>

using namespace std;
int numTest;
int n, K;
int a[200005];
int dp[200005];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dp[i] = -1;
    }
    int ans = 0;
    if (a[1] == K) {
      dp[1] = 1;
    }
    for (int i = 1; i < n; i++) {
      if (a[i + 1] == K) {
        dp[i + 1] = 1;
        continue;
      }
      if (dp[i] != -1) {
        if (a[i + 1] == a[i] - 1) {
          dp[i + 1] = dp[i] + 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (dp[i] == K) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}