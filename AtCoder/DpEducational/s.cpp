#include <bits/stdc++.h> 

using namespace std; 
const int mod = 1000000007; 
int dp[10005][100][3]; 
string s; 
int d; 

int main () {
  cin >> s >> d; 
  int n = (int) s.size(); 
  for (int x = 1; x <= 9; x++) {
    if (x < s[0] - '0') {
      dp[1][x % d][0]++; 
    }
    else if (x == s[0] - '0') {
      dp[1][x % d][1]++; 
    }
    else {
      dp[1][x % d][2]++; 
    }
  }
  for (int i = 1; i < n; i++) {
    for (int r = 0; r < d; r++) {
      for (int sta = 0; sta < 3; sta++) {
        if (dp[i][r][sta] == 0) {
          continue; 
        }
        int cur = dp[i][r][sta]; 
        for (int x = 0; x <= 9; x++) {
          if (sta == 0) {
            (dp[i + 1][(r + x) % d][0] += cur) %= mod; 
          }                                             
          else if (sta == 2) {
            (dp[i + 1][(r + x) % d][2] += cur) %= mod; 
          }
          else {
            if (x < s[i] - '0') {
              (dp[i + 1][(r + x) % d][0] += cur) %= mod; 
            }
            else if (x > s[i] - '0') {
              (dp[i + 1][(r + x) % d][2] += cur) %= mod; 
            }
            else {
              (dp[i + 1][(r + x) % d][1] += cur) %= mod; 
            }
          }
        }
      }
    }
  }
  int res = 0; 
  for (int i = 1; i <= n; i++) {
    for (int sta = 0; sta <= (i < n ? 2 : 1); sta++) {
      (res += dp[i][0][sta]) %= mod; 
    }
  }
  cout << res; 
  return 0; 
}