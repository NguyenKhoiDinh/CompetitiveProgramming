#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 505;
int val[2 * MAX_N];
int dp[2 * MAX_N][2 * MAX_N];
int sum[2 * MAX_N];

class PizzaEatingGame {
  public:
  int eat(vector <int> olives) {
    int n = (int) olives.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
      total += olives[i];
    }
    for (int i = 0; i < 2 * MAX_N; i++) {
      val[i] = olives[i % n];
    }
    sum[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
      sum[i] = sum[i - 1] + val[i - 1];
    }
    for (int i = 1; i <= 2 * n; i++) {
      dp[i][i] = val[i - 1];
    }
    for (int r = 2; r <= 2 * n; r++) {
      for (int l = r - 1; l >= max(1, r - n + 1); l--) {
        int sumRange = sum[r] - sum[l - 1];
        dp[l][r] = sumRange - dp[l + 1][r];
        dp[l][r] = max(dp[l][r], sumRange - dp[l][r - 1]);
        for (int k = l; k <= r - 1; k++) {
          dp[l][r] = max(dp[l][r], sumRange - dp[l][k] - dp[k + 1][r]);
        }
      }
    }

  }
};

int main () {
  return 0;
}