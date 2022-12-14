#include <bits/stdc++.h> 

using namespace std;
int numTest; 
string s; 
const int inf = 1000000007; 
int dp[200005][26][2]; 
int pos[200005][26]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s; 
    int n = (int) s.size(); 
    for (int i = 0; i <= n; i++) {
      for (int c = 0; c < 26; c++) {
        dp[i][c][0] = dp[i][c][1] = -1; 
        pos[i][c] = 0; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int c = 0; c < 26; c++) {
        pos[i][c] = pos[i - 1][c]; 
      }
      pos[i][s[i - 1] - 'a'] = i; 
    }
    for (int c = 0; c < 26; c++) {
      dp[0][c][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int curChar = s[i - 1] - 'a'; 
      for (int c = 0; c < 26; c++) {
        dp[i][c][0] = dp[i - 1][c][0];
        dp[i][c][1] = dp[i - 1][c][1]; 
      }
      for (int c = 0; c < 26; c++) {
        if (dp[i - 1][c][0] != -1) {
          dp[i][curChar][1] = max(dp[i][curChar][1], dp[i - 1][c][0] + 1); 
        }
      }
      if (dp[i - 1][curChar][1] != -1) {
        dp[i][curChar][0] = max(dp[i][curChar][0], dp[i - 1][curChar][1] + 1); 
      }
    }
    int ans = -1; 
    for (int c = 0; c < 26; c++) {
      ans = max(ans, dp[n][c][0]); 
    }
    cout << n - ans << endl; 
  }
  return 0; 
}