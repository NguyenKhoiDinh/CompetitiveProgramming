#include <iostream>

using namespace std;
const int MAX_N = 2000005;
const long long MOD = 1000000007;

long long fibo[MAX_N];
long long fact[MAX_N], invFact[MAX_N];

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long subProblem = POW(x, n >> 1);
  subProblem = (subProblem * subProblem) % MOD;
  if (n % 2 == 1) {
    (subProblem *= x) %= MOD;
  }
  return subProblem;
}

void init() {
  fact[0] = 1LL;
  invFact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % MOD;
    invFact[i] = POW(fact[i], MOD - 2);
  }
  fibo[0] = 0LL;
  fibo[1] = 1LL;
  for (int i = 2; i < MAX_N; i++) {
    fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
  }
}

long long C(int n, int k) {
  long long ans = fact[n];
  (ans *= invFact[k]) %= MOD;
  (ans *= invFact[n - k]) %= MOD;
  return ans;
}

int main () {
  init();
  int x, y;
  cin >> x >> y;
  long long res = 0LL;
  for (int i = 1; i <= y; i++) {
    int dx = x - 1;
    int dy = y - i;
    (res += (C(dx + dy, dy) * fibo[i]) % MOD) %= MOD;
  }
  for (int i = 1; i <= x; i++) {
    int dx = x - i;
    int dy = y - 1;
    (res += (C(dx + dy, dx) * fibo[i]) % MOD) %= MOD;
  }
  cout << res;
  return 0;
}