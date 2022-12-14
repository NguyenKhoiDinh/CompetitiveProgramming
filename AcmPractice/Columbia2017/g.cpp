#include <bits/stdc++.h> 

using namespace std; 
const int MOD = 1000000007;
const int MAX_N = 22; 
int dp[MAX_N];
int n; 

string changeToString(int x) {
  string res = "";
  while (x > 0) {
    int r = x % 10;
    res += (char) (r + '0');
    x /= 10; 
  }
  reverse(res.begin(), res.end()); 
  return res; 
}

int main () {
  while (cin >> n) {
    string s = ""; 
    for (int i = 2; i <= (int) sqrt(n); i++) {
      while (n % i == 0) {
        s += changeToString(i); 
        n /= i; 
      }
    }
    if (n > 1) {
      s += changeToString(n);
    }
    sort(s.begin(), s.end());
    int ans = 0;
    do {
      int len = (int) s.size(); 
      for (int i = 0; i <= len; i++) {
        dp[i] = 0; 
      }
      dp[0] = 1; 
      for (int i = 0; i < len; i++) {
        if (dp[i] == 0) {
          continue; 
        }
        if (s[i] - '0' >= 1 && s[i] - '0' <= 9) {
          (dp[i + 1] += dp[i]) %= MOD;
        }
        if (i + 2 <= len) {
          if ((s[i] - '0') * 10 + s[i + 1] - '0' >= 10 && (s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
            (dp[i + 2] += dp[i]) %= MOD; 
          }
        }
      }
      (ans += dp[len]) %= MOD;
    }
    while (next_permutation(s.begin(), s.end()));
    cout << ans << endl;
  }
  return 0; 
}