#include <iostream>
#include <string>

using namespace std;
const int MAX_N = 55;
string s;
string st = "abcdefghijklmnopqrstuvwxyz";
int dp[MAX_N][MAX_N];
int n, m;

int main () {
  freopen("input.txt", "r", stdin);
  cin >> s;
  n = (int) s.size();
  m = 26;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == st[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << 26 - dp[n][m];
  return 0;
}