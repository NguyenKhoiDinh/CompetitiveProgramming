#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 33; 
int dp[MAX_N][MAX_N][3];
int l, r, k, base; 

string convert(int n) {
  string res = "";
  while (n > 0) {
    int r = n % base; 
    n /= base; 
    res += (char) (r + '0');
  }
  reverse(res.begin(), res.end());
  return res; 
}

int calc(int N) {
  if (N == 0) {
    return 0; 
  }
  string s = convert(N);
  int len = (int) s.size(); 
  memset(dp, 0, sizeof(dp));
  dp[1][1][1 == s[0] - '0'] = 1;
  for (int i = 1; i < len; i++) {
    for (int numDigit = 1; numDigit <= k; numDigit++) {
      for (int status = 0; status <= 2; status++) {
        if (dp[i][numDigit][status] == 0) {
          continue; 
        }
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
          dp[i + 1][numDigit + (x == 1)][nextStatus] += dp[i][numDigit][status];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= len; i++) {
    for (int status = 0; status <= (i == len ? 1 : 2); status++) {
      ans += dp[i][k][status];
    }
  }
  return ans;
}

int main () {
  cin >> l >> r >> k >> base; 
  cout << calc(r) - calc(l - 1);
  return 0; 
}