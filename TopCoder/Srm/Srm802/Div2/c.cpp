#include <bits/stdc++.h>

using namespace std;
double dp[17][(1 << 6) + 3];

class DisjointDiceValues {
  public:
  double getProbability(int A, int B) {
    dp[0][0] = 1.0;
    for (int i = 0; i < A; i++) {
      for (int mask = 0; mask < (1 << 6); mask++) {
        if (dp[i][mask] == 0.0) {
          continue;
        }
        for (int x = 0; x <= 5; x++) {
          dp[i + 1][mask | (1 << x)] += dp[i][mask] * 1.0 / 6;
        }
      }
    }
    double res = 0.0;
    for (int mask = 1; mask < (1 << 6); mask++) {
      int cnt = 6 - (int) __builtin_popcount(mask);
      double value = dp[A][mask];
      for (int i = 1; i <= B; i++) {
        value *= 1.0 * cnt / 6;
      }
      res += value;
    }
    return res;
  }
};

int main () {
  return 0;
}