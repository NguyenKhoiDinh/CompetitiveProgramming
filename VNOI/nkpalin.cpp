#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 2005; 
string s; 
int dp[MAX_N][MAX_N];
int n; 

int main () {
  cin >> s;
  n = (int) s.size(); 
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 1; 
  }
  for (int j = 2; j <= n; j++) {
    for (int i = j - 1; i >= 1; i--) {
      if (s[i - 1] == s[j - 1]) {
        dp[i][j] = dp[i + 1][j - 1] + 2; 
      }
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = 1; 
  int j = n;
  int l = 0; 
  int r = dp[1][n] - 1;  
  string res; 
  res.resize(dp[1][n]); 
  while (i <= j) {
    if (s[i - 1] == s[j - 1]) {
      res[l] = s[i - 1]; 
      res[r] = s[j - 1]; 
      i++; 
      j--; 
      l++;
      r--; 
    }
    else {
      if (dp[i][j] == dp[i + 1][j]) {
        i++;
      }
      else {
        j--;
      }
    }
  }
  cout << res;
  return 0; 
}