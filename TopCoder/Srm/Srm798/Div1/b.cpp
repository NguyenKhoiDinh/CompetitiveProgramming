#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1505;
const long long MOD = 1000000007;
long long D[MAX_N];
long long dp[MAX_N];
long long C[MAX_N][MAX_N];
long long correctDerangement[MAX_N];

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long subProblem = POW(x, n >> 1);
  (subProblem *= subProblem) %= MOD;
  if (n & 1) {
    (subProblem *= x) %= MOD;
  }
  return subProblem;
}

class ExpectedValue {
  public:
  int solve(int N) {
    for (int i = 0; i <= N; i++) {
      C[i][0] = 1;
      C[i][i] = 1;
    }
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
      }
    }
    D[0] = 0;
    D[1] = 0;
    D[2] = 1;
    D[3] = 2;
    for (int i = 4; i <= N; i++) {
      D[i] = 1LL * (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
    }
    correctDerangement[0] = 0;
    correctDerangement[1] = 0;
    correctDerangement[2] = 1;
    for (int i = 3; i <= N; i++) {
      correctDerangement[i] = D[i];
      for (int l = 2; l < i; l++) {
        long long mul = C[i - 1][l - 1];
        (mul *= correctDerangement[l]) %= MOD;
        (mul *= D[i - l]) %= MOD;
        correctDerangement[i] -= mul;
        if (correctDerangement[i] < 0) {
          correctDerangement[i] += MOD;
        }
      }
    }
    long long ans = POW(D[N], MOD - 2);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) {
      dp[i] = (correctDerangement[i] * (i - 1)) % MOD;
      for (int l = 2; l < i; l++) {
        long long mul = C[i - 1][l - 1];
        (mul *= correctDerangement[l]) %= MOD;
        (mul *= ((D[i - l] * (l - 1)) % MOD + dp[i - l]) % MOD) %= MOD;
        (dp[i] += mul) %= MOD;
      }
    }
    (ans *= dp[N]) %= MOD;
    return (int) ans;
  }
};

ExpectedValue E;

int main () {
  cout << E.solve(6);
  return 0;
}