#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105; 
int dp[MAX_N][MAX_N][3]; 
int n, k; 

string convert(int n) {
  string res = "";
  if (n == 0) {
    return "0";
  }
  while (n > 0) {
    int r = n % 2; 
    n /= 2; 
    res += (char) (r + '0');
  }
  reverse(res.begin(), res.end());
  return res;
}

int main () {
  while (cin >> n >> k) {
    if (n == 0) {
      cout << (k == 1 ? 1 : 0) << endl; 
      continue; 
    }
    string s = convert(n);
    int ans = 0; 
    if (k == 1) {
      ans = 1; 
    }
    int len = (int) s.size();
    if (k > len) {
      cout << 0 << endl; 
      continue; 
    }
    memset(dp, 0, sizeof(dp));
    dp[1][0][1] = 1; 
    for (int i = 1; i < len; i++) {
      for (int numDigit = 0; numDigit <= k; numDigit++) {
        for (int status = 0; status <= 2; status++) {
          for (int x = 0; x <= 1; x++) {
            int nextStatus = status; 
            if (status == 1) {
              if (x < s[i] - '0') {
                nextStatus = 0; 
              }
              else if (x == s[i] - '0') {
                nextStatus = 1; 
              }
              else {
                nextStatus = 2; 
              }
            }
            dp[i + 1][numDigit + (x == 0)][nextStatus] += dp[i][numDigit][status]; 
          }
        }
      }
    }
    for (int i = 1; i <= len; i++) {
      for (int status = 0; status <= (i == len ? 1 : 2); status++) {
        ans += dp[i][k][status];
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}