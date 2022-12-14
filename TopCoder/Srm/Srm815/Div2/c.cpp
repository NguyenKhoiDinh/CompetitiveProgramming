#include <bits/stdc++.h>

using namespace std;
int dp[55][(1 << 20) + 5]; 
int fact[55];

class EllysKeys {
  public:
  int getMax(vector <string> keys) {
    int n = (int) keys.size();
    int m = (int) keys[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (keys[i][j] == '^') {
          fact[i] |= (1 << j);
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        dp[i][mask] = -1;
      }
    }  
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        if (dp[i][mask] == -1) {
          continue;
        }
        dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);
        if ((mask & fact[i]) == 0) {
          dp[i + 1][mask | fact[i]] = max(dp[i + 1][mask | fact[i]], dp[i][mask] + 1); 
        }
      }
    }
    int ans = -1;
    for (int mask = 0; mask < (1 << m); mask++) {
      ans = max(ans, dp[n][mask]);
    }
    return ans;
  }
};
EllysKeys E;

int main () {
  return 0;
}