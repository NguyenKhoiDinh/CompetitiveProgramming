#include <bits/stdc++.h>

using namespace std;
const int inf = 100007;
const int MAX_N = 1005;
int numTest;
int n, X, Y;
string s;
int dp[MAX_N][2];

void update(int &a, int b) {
  a = min(a, b);
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> X >> Y >> s;
    n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      dp[i][0] = dp[i][1] = inf;
    }
    if (s[0] == '?') {
      dp[1][0] = dp[1][1] = 0;
    }
    else if (s[0] == 'C') {
      dp[1][0] = 0;
    }
    else {
      dp[1][1] = 0;
    }
    for (int i = 1; i < n; i++) {
      for (int type = 0; type <= 1; type++) {
        if (dp[i][type] == inf) {
          continue;
        }
        if (s[i] == '?') {
          update(dp[i + 1][type], dp[i][type]);
          if (type == 0) {
            update(dp[i + 1][1], dp[i][type] + X);
          }
          else {
            update(dp[i + 1][0], dp[i][type] + Y);
          }
        }
        else if (s[i] == 'C') {
          if (type == 0) {
            update(dp[i + 1][0], dp[i][type]);
          }
          else {
            update(dp[i + 1][0], dp[i][type] + Y);
          }
        }
        else {
          if (type == 0) {
            update(dp[i + 1][1], dp[i][type] + X);
          }
          else {
            update(dp[i + 1][1], dp[i][type]);
          }
        }
      }
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
  }
  return 0;
}