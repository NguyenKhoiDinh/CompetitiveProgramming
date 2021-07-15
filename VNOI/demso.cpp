#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 33; 
long long dp[MAX_N][MAX_N][10][3];
int l, r, d, k; 

string convert(long long n) {
  string res = "";
  while (n > 0) {
    int r = n % 10; 
    n /= 10; 
    res += (char) (r + '0');
  }
  reverse(res.begin(), res.end());
  return res; 
}

long long calc(long long N) {
  if (N == 0) {
    return 0; 
  }
  string s = convert(N);
  int len = (int) s.size(); 
  memset(dp, 0, sizeof(dp));
  for (int x = 1; x <= 9; x++) {
    int status = 0;
    if (x == s[0] - '0') {
      status = 1; 
    }
    else if (x > s[0] - '0') {
      status = 2; 
    }
    dp[1][0][0][status]++;
  }
  for (int i = 1; i < len; i++) {
    for (int numDiff = 0; numDiff <= k; numDiff++) {
      for (int prevDig = 0; prevDig <= 9; prevDig++) {
        for (int status = 0; status <= 2; status++) {
          if (dp[i][numDiff][prevDig][status] == 0) {
            continue; 
          }
          for (int x = 0; x <= 9; x++) {
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
            dp[i + 1][numDiff + (abs(x - prevDig) <= d)][x][nextStatus] += dp[i][numDiff][prevDig][status];
          }
        }
      }
    }
  }
  long long ans = 0LL; 
  for (int i = 1; i <= len; i++) {
    for (int prevDig = 0; prevDig <= 9; prevDig++) {
      for (int status = 0; status <= (i == len ? 1 : 2); status++) {
        ans += dp[i][k][prevDig][status];
      }
    }
  }
  return ans;
}

int main () {
  freopen("input.txt", "r", stdin);
  cin >> l >> r >> d >> k; 
  cout << calc(r) - calc(l - 1);
  return 0; 
}