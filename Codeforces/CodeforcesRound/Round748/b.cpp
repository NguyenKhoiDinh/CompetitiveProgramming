#include <bits/stdc++.h> 

using namespace std;
int numTest;
int dp[20][25];
string s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    int n = (int) s.size();
    for (int i = 0; i <= n; i++) {
      for (int r = 0; r < 25; r++) {
        dp[i][r] = -1;
      }
    }
    dp[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int r = 0; r < 25; r++) {
        if (dp[i][r] == -1) {
          continue;
        }
        dp[i + 1][r] = max(dp[i + 1][r], dp[i][r]);
        dp[i + 1][(r * 10 + s[i] - '0') % 25] = max(dp[i + 1][(r * 10 + s[i] - '0') % 25], dp[i][r] + 1); 
      }
    }
    cout << n - dp[n][0] << endl;
  }
  return 0; 
}