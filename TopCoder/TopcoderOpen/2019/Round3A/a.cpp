#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 1005;
long long dp[MAX_N][MAX_N];
long long C[MAX_N][MAX_N];

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long tmp = POW(x, n >> 1);
  (tmp *= tmp) %= MOD;
  if (n & 1) {
    (tmp *= x) %= MOD;
  }
  return tmp;
}

class FamilySeatingArrangement {
  public:
  int countWays(vector <int> a, int k) {
    for (int i = 0; i < MAX_N; i++) {
      C[i][0] = 1LL;
      C[i][i] = 1LL;
    }
    for (int i = 1; i < MAX_N; i++) {
      for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }
    int n = (int) a.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    dp[0][0] = 1LL;
    for (int i = 0; i < n; i++) {
      for (int numTable = 0; numTable <= k; numTable++) {
        if (dp[i][numTable] == 0) {
          continue;
        }
        long long curVal = dp[i][numTable];
        if (numTable < k) {
          (dp[i + 1][numTable + 1] += 1LL * (curVal * (k - numTable)) % MOD) %= MOD;
        }
        if (numTable > 0) {
          (dp[i + 1][numTable] += 1LL * (curVal * numTable) % MOD) %= MOD;
        }
      }
    }
    long long res = 0LL;
    for (int numTable = 1; numTable <= k; numTable++) {
      int availTable = k + 1 - numTable;
      long long val = dp[n][numTable];
      (val *= POW(1LL * availTable, sum)) %= MOD;
      (res += val) %= MOD;
    }
    return (int) res;
  }
};