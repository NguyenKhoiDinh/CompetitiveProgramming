#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
const long long MOD = 998244353;
const int MAX_N = 505;
long long dp[MAX_N][MAX_N][2];
struct element {
  char command;
  long long value;
};
element a[MAX_N];
int n; 

long long dynamicProgramming(int position) {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    for (int smaller = 0; smaller <= i; smaller++) {
      for (int status = 0; status <= 1; status++) {
        if (dp[i][smaller][status] == 0) {
          continue;
        }
        long long curValue = dp[i][smaller][status];
        if (i + 1 == position) {
          (dp[i + 1][smaller][1] += curValue) %= MOD; 
        }
        else {
          (dp[i + 1][smaller][status] += curValue) %= MOD;
          if (a[i + 1].command == '+') {
            if (a[i + 1].value < a[position].value) {
              (dp[i + 1][smaller + 1][status] += curValue) %= MOD;
            }
            else if (a[i + 1].value == a[position].value) {
              if (i + 1 < position) {
                (dp[i + 1][smaller + 1][status] += curValue) %= MOD; 
              }
              else {
                (dp[i + 1][smaller][status] += curValue) %= MOD;
              }
            }
            else {
              (dp[i + 1][smaller][status] += curValue) %= MOD;
            }  
          }
          else {
            if (smaller > 0) {
              (dp[i + 1][smaller - 1][status] += curValue) %= MOD; 
            }
            else if (status == 0) {
              (dp[i + 1][smaller][status] += curValue) %= MOD; 
            }
          }
        }
      }
    }
  }
  long long ret = 0LL; 
  for (int smaller = 0; smaller <= n; smaller++) {
    (ret += dp[n][smaller][1]) %= MOD;
  }
  return ret;
}

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].command;
    if (a[i].command == '+') {
      cin >> a[i].value;
    }
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    if (a[i].command == '-') {
      continue;
    }
    long long ways = dynamicProgramming(i);
    (ans += (ways * a[i].value) % MOD) %= MOD;
  }
  cout << ans;
  return 0;
}