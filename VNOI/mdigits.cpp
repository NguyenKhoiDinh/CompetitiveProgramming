#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 12; 
int dp[MAX_N][MAX_N][3];
int cntr[10], cntl[10];
int l, r; 

string convert(int v) {
  string res = ""; 
  if (v == 0) {
    return "0";
  }
  while (v > 0) {
    int r = v % 10;
    v /= 10;
    res += (char) (r + '0'); 
  }
  reverse(res.begin(), res.end());
  return res; 
}

void solve(int v, int cnt[10]) {
  string N = convert(v);
  int len = (int) N.size(); 
  for (int digit = 0; digit <= 9; digit++) {
    memset(dp, 0, sizeof(dp));
    for (int x = 1; x <= 9; x++) {
      int status = 0;
      if (x == N[0] - '0') {
        status = 1; 
      }
      else if (x > N[0] - '0') {
        status = 2; 
      }
      dp[1][x == digit][status]++;
    }
    for (int i = 1; i < len; i++) {
      for (int numbDigit = 0; numbDigit <= i; numbDigit++) {
        for (int status = 0; status <= 2; status++) {
          if (dp[i][numbDigit][status] == 0) {
            continue; 
          }
          for (int x = 0; x <= 9; x++) {
            int newStatus = status; 
            if (status == 1) {
              if (x < N[i] - '0') {
                newStatus = 0; 
              }
              else if (x > N[i] - '0') {
                newStatus = 2; 
              }
            }
            dp[i + 1][numbDigit + (x == digit)][newStatus] += dp[i][numbDigit][status];
          }
        }
      }
    }
    for (int i = 1; i <= len; i++) {
      for (int numbDigit = 1; numbDigit <= i; numbDigit++) {
        for (int status = 0; status <= (i < len ? 2 : 1); status++) {
          cnt[digit] += numbDigit * dp[i][numbDigit][status];
        }
      }
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  while (true) {
    cin >> l >> r;
    if (l == 0 && r == 0) {
      break;
    } 
    if (l > r) { 
      swap(l, r);
    }
    for (int digit = 0; digit <= 9; digit++) {
      cntr[digit] = cntl[digit] = 0;
    }
    solve(r, cntr);
    solve(l - 1, cntl); 
    for (int digit = 0; digit <= 9; digit++) {
      cout << cntr[digit] - cntl[digit] << ' ';
    }
    cout << endl;
  }
  return 0; 
}