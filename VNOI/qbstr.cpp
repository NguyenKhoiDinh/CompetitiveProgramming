#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 2005; 
int dp[MAX_N][MAX_N];
string s1, s2; 

int main () {
  cin >> s1 >> s2; 
  int n = (int) s1.size(); 
  int m = (int) s2.size(); 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1; 
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[n][m];
  return 0; 
}