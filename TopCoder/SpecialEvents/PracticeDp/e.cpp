#include <bits/stdc++.h> 

using namespace std; 
int dp[55][55]; 

int calc(const string &s1, const string &s2) {
  memset(dp, 0, sizeof(dp));
  int n = (int) s1.size(); 
  int m = (int) s2.size();
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int j = 1; j <= m; j++) {
    dp[0][j] = j;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1]; 
      }
      else {
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1; 
      }
    }
  }
  return dp[n][m];
}

class MakeSquare {
  public: 
  int minChanges(string S) {
    int ans = 1000005; 
    for (int i = 0; i <= (int) s.size(); i++) {
      string s1 = "";
      string s2 = ""; 
      for (int j = 0; j < i; j++) {
        s1 += s[j]; 
      } 
      for (int j = i; j < (int) s.size(); j++) {
        s2 += s[j];
      }
      ans = min(ans, calc(s1, s2)); 
    }  
    return ans; 
  }
};

int main () {
  return 0; 
}