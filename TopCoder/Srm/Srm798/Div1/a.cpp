#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 3005;
const int MAX_V = 10005;
long long dp[MAX_N][MAX_V];
long long pw2[MAX_N];

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long subProblem = POW(x, n >> 1);
  (subProblem *= subProblem) %= MOD;
  if (n % 2 == 1) {
    (subProblem *= x) %= MOD;
  }
  return subProblem;
}

class SuperSubset {
  public:
  int solve(vector <int> A, int Y) {
    int n = (int) A.size();
    pw2[0] = 1LL;
    for (int i = 1; i <= n; i++) {
      pw2[i] = (pw2[i - 1] * 2LL) % MOD;
    }
    dp[0][0] = pw2[n];
    long long inv2 = POW(2, MOD - 2);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= Y; j++) {
        if (dp[i][j] == 0) {
          continue;
        }
        (dp[i + 1][j] += dp[i][j]) %= MOD;
        if (j + A[i] <= Y) {
          (dp[i + 1][j + A[i]] += (dp[i][j] * inv2) % MOD) %= MOD;
        }
      }
    }
    return (int) dp[n][Y];
  }
};

SuperSubset S;

int main () {
  cout << S.solve({1, 1, 2, 3, 4},
6);
  return 0;
}