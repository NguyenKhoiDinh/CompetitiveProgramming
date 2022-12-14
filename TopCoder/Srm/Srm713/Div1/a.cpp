#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 1000005;
set <long long> S;

class PowerEquation {
  public:
  int count(int n) {
    long long res = (1LL * n * n) % MOD;
    (res += (1LL * (n - 1) * n) % MOD) %= MOD;
    for (int p = 2; p * p <= n; p++) {
      if (S.find((long long) p) != S.end()) {
        continue;
      }
      int cnt = 0;
      long long value = p;
      while (value <= n) {
        S.insert(value);
        cnt++;
        value *= 1LL * p;
      }
      for (int x = 1; x <= cnt; x++) {
        for (int y = 1; y <= cnt; y++) {
          if (x != y) {
            int xx = x;
            int yy = y;
            int gcd = __gcd(xx, yy);
            xx /= gcd;
            yy /= gcd;
            (res += n / max(xx, yy)) %= MOD;
          }
        }
      }
    }
    return (int) res;
  }
};               

PowerEquation P; 

int main () {
  cout << P.count(10);
  return 0; 
}