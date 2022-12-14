#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
const int MOD = 1000000007;
int dp[MAX_N][3];
int n, k, ans = 0; 
string s; 

void dynamicProgramming(int half) {
  memset(dp, 0, sizeof(dp));
  for (int c = 0; c < k; c++) {
    if (c > s[0] - 'a') {
      break; 
    }
    int status = 0; 
    if (c == s[0] - 'a') {
      status = 1; 
    }
    dp[1][status]++; 
  }
  for (int i = 1; i < half; i++) {
    for (int status = 0; status <= 1; status++) {
      if (dp[i][status] == 0) {
        continue; 
      }
      for (int c = 0; c < k; c++) {
        int newStatus = status; 
        if (status == 1) {
          if (c < s[i] - 'a') {
            newStatus = 0; 
          }
          else if (c > s[i] - 'a') {
            break; 
          }
        }
        (dp[i + 1][newStatus] += dp[i][status]) %= MOD; 
      }
    }
  }
  (ans += dp[half][0]) %= MOD; 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> k; 
    cin >> s; 
    int half = (n + 1) / 2 - 1; 
    string shalf = ""; 
    for (int i = 0; i <= half; i++) {
      shalf += s[i]; 
    }
    for (int i = (n % 2 == 1 ? half - 1 : half); i >= 0; i--) {
      shalf += s[i]; 
    }
    ans = 0; 
    if (shalf < s) {
      ans++; 
    }
    dynamicProgramming(half + 1);
    cout << ans << endl; 
  }
  return 0;
}