#include <bits/stdc++.h>

using namespace std;
int numTest;
const int MAX_N = 20; 
long long dp[MAX_N][3]; 
long long L, R; 

string change(long long N) {
  if (N == 0) {
    return "0";
  }
  string res = ""; 
  while (N > 0) {
    int x = N % 10; 
    N /= 10;
    res += (char) (x + '0');
  }
  reverse(res.begin(), res.end());
  return res;
}

long long solve(long long numb) {
  memset(dp, 0LL, sizeof(dp));
  string N = change(numb);
  int len = (int) N.size();
  for (int x = 1; x <= 9; x += 2) {
    int status;
    if (x < N[0] - '0') {
      status = 0; 
    }
    else if (x == N[0] - '0') {
      status = 1;
    }
    else {
      status = 2; 
    }
    dp[1][status]++;
  }
  for (int i = 1; i < len; i++) {
    for (int status = 0; status <= 2; status++) {
      if (dp[i][status] == 0) {
        continue; 
      }
      for (int x = (i % 2 == 1 ? 0 : 1); x <= 9; x += 2) {
        int newStatus = status;
        if (status == 1) {
          if (x < N[i] - '0') {
            newStatus = 0; 
          }
          else if (x > N[i] - '0') {
            newStatus = 2; 
          }
        }
        dp[i + 1][newStatus] += dp[i][status];
      }
    }
  }
  long long res = 0LL;
  for (int i = 1; i <= len; i++) {
    for (int status = 0; status <= (i < len ? 2 : 1); status++) {
      res += dp[i][status];
    }
  }
  return res;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> L >> R; 
    cout << solve(R) - solve(L - 1) << endl; 
  }
  return 0;
}