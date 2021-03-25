#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
const long long MOD = 1000000007;
long long fact[MAX_N], invFact[MAX_N];

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

void init() {
  fact[0] = 1LL;
  invFact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    invFact[i] = POW(fact[i], MOD - 2);
  }
}

long long C(int n, int k) {
  long long res = fact[n];
  (res *= invFact[k]) %= MOD;
  (res *= invFact[n - k]) %= MOD;
  return res;
}

int main () {
  init();
  int n, k;
  cin >> n >> k;
  cout << C(n, k);
  return 0;
}