#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105; 
struct stones {
  int S, E, L; 
  bool operator < (const stones &other) const {
    return (S * other.L < other.S * L); 
  }
};

int dp[MAX_N][MAX_N * MAX_N];
stones a[MAX_N];
int n; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].S >> a[i].E >> a[i].L; 
    }
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < MAX_N * MAX_N; j++) {
        dp[i][j] = -1; 
      }
    }
    dp[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < MAX_N * MAX_N; j++) {
        if (dp[i][j] == -1) {
          continue; 
        }
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]); 
        if (a[i + 1].E - j * a[i + 1].L > 0) {
          dp[i + 1][j + a[i + 1].S] = max(dp[i + 1][j + a[i + 1].S], dp[i][j] + a[i + 1].E - j * a[i + 1].L);
        }
      }
    }
    int res = -1; 
    for (int j = 0; j < MAX_N * MAX_N; j++) {
      res = max(res, dp[n][j]);
    }
    cout << res << endl;
  }
  return 0; 
}