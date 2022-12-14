#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
const int MAX_K = 33;
int numTest;
int n, K, P;
int a[MAX_N][MAX_K];
int sum[MAX_N][MAX_K];
int dp[MAX_N][MAX_N * MAX_K];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> K >> P;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= K; j++) {
        int x;
        cin >> x;
        sum[i][j] = sum[i][j - 1] + x;
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= P; j++) {
        dp[i][j] = -1;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= P; j++) {
        if (dp[i][j] == -1) {
          continue;
        }
        for (int x = 0; x <= K; x++) {
          if (j + x <= P) {
            dp[i + 1][j + x] = max(dp[i + 1][j + x], dp[i][j] + sum[i + 1][x]);
          }
        }
      }
    }
    cout << dp[n][P] << endl;
  }
  return 0;
}