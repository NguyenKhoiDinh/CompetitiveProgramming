#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 10005;
const int inf = 10009;
int numTest;
int a[MAX_N];
int n;
int dp[MAX_N][4];

void update(int &a, int b) {
  a = min(a, b);
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int note = 0; note < 4; note++) {
        dp[i][note] = inf;
      }
    }
    for (int note = 0; note < 4; note++) {
      dp[1][note] = 0;
    }
    for (int i = 1; i < n; i++) {
      for (int note = 0; note < 4; note++) {
        if (dp[i][note] == inf) {
          continue;
        }
        for (int nextNote = 0; nextNote < 4; nextNote++) {
          if (a[i] < a[i + 1]) {
            update(dp[i + 1][nextNote], dp[i][note] + (note >= nextNote));
          }
          else if (a[i] == a[i + 1]) {
            update(dp[i + 1][nextNote], dp[i][note] + (note != nextNote));
          }
          else {
            update(dp[i + 1][nextNote], dp[i][note] + (note <= nextNote));
          }
        }
      }
    }
    int ans = inf;
    for (int note = 0; note < 4; note++) {
      update(ans, dp[n][note]);
    }
    cout << ans << endl;
  }
  return 0;
}