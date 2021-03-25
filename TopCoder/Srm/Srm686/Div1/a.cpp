#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 44;
long long dp[MAX_N][MAX_N];

class BracketSequenceDiv1 {
  public:
  long long count(string s) {
    int n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      dp[i][i] = 0;
    }
    for (int l = 1; l <= n; l++) {
      for (int r = l + 1; r <= n; r++) {
        if ((s[l - 1] == '(' && s[r - 1] == ')') || (s[l - 1] == '[' && s[r - 1] == ']')) {
          dp[l][r] = dp[l + 1][r - 1] + (l + 1 > r - 1 ? 0 : 1);
        }
        for (int k = l; k < r; k++) {
          dp[l][r] += (dp[l][k] + 1) * (dp[k + 1][r] + 1);
          dp[l][r]--;
        }
      }
    }
    return dp[1][n];
  }
};

int main () {
  return 0;
}