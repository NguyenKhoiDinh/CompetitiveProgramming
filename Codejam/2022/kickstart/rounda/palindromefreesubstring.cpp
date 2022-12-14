#include <bits/stdc++.h> 

using namespace std; 
int numTest;
int n;
string s;  
int dp[50005][33]; 

bool checkPalind(int mask, int maxbit) {
  string trace = "";
  for (int i = 0; i <= maxbit; i++) {
    int bit = ((mask & (1 << i)) > 0); 
    trace += (char) (bit + '0'); 
  } 
  string rev_trace = trace;
  reverse(rev_trace.begin(), rev_trace.end()); 
  return (trace == rev_trace); 
}
                
int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n;
    cin >> s; 
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << 5); mask++) {
        if (dp[i][mask] == 0) {
          continue; 
        }
        if (s[i] == '0' || s[i] == '?') { 
          int newmask5 = (mask << 1);
          newmask5 &= (1 << 5) - 1;  
          int newmask6 = mask << 1;
          newmask6 &= (1 << 6) - 1;  
          if (i + 1 >= 6) {
            if (checkPalind(newmask5, 4) == true && checkPalind(newmask6, 5) == true) {
              dp[i + 1][newmask5] = 1; 
            }
          }
          else if (i + 1 == 5) {
            if (checkPalind(newmask5, 4) == true) {
              dp[i + 1][newmask5] = 1; 
            }
          }
          else {
            dp[i + 1][newmask5] = 1; 
          }
        }
        if (s[i] == '1' || s[i] == '?') {     
          int newmask5 = (mask << 1) + 1;
          newmask5 &= (1 << 5) - 1;  
          int newmask6 = (mask << 1) + 1;
          newmask6 &= (1 << 6) - 1;  
          if (i + 1 >= 6) {
            if (checkPalind(newmask5, 4) == true && checkPalind(newmask6, 5) == true) {
              dp[i + 1][newmask5] = 1; 
            }
          }
          else if (i + 1 == 5) {
            if (checkPalind(newmask5, 4) == true) {
              dp[i + 1][newmask5] = 1; 
            }
          }
          else {
            dp[i + 1][newmask5] = 1; 
          }
        }
      }
    }
    bool ans = false; 
    for (int mask = 0; mask < (1 << 5); mask++) {
      if (dp[n][mask] == 1) {
        ans = true; 
        break; 
      }
    } 
    cout << (ans == true ? "POSSIBLE" : "IMPOSSIBLE") << endl; 
  }
  return 0; 
}