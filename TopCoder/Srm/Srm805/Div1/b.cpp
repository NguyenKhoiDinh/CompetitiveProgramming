
#include <bits/stdc++.h> 

using namespace std; 
const int MOD = 1000000007;
const int MAX_LENGTH = 5005; 
const int MAX_N = 1005;
int dp[MAX_LENGTH][MAX_N];
int nxt[MAX_LENGTH][10]; 

class SubmultiplesOfN {
  public:
  int count(string B, int N) {
    int len = (int) B.size();
    for (int i = 0; i < len; i++) {
      for (int d = 0; d <= 9; d++) {
        nxt[i][d] = -1; 
      }
      for (int j = i + 1; j <= len; j++) {
        if (nxt[i][s[j - 1] - '0'] == -1) {
          nxt[i][s[j - 1] - '0'] = j;
        }
      }
    }
    dp[0][0] = 1; 
    for (int i = 0; i < len; i++) {
      for (int r = 0; r < N; r++) {
        if (dp[i][r] == 0) {
          continue; 
        }
        for (int dig = (i == 0 ? 1 : 0); dig <= 9; dig++) {
          int pos = nxt[i][dig]; 
          if (pos != -1) {
            (dp[pos][(r * 10 + dig) % N] += dp[i][r]) %= MOD;
          }
        }
      }
    }
    int ans = 0; 
    for (int i = 1; i <= len; i++) {
      (ans += dp[i][0]) %= MOD; 
    }
    return ans; 
  }
};

int main () {
  return 0; 
}