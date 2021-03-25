#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 1000005;
bool isPrime[MAX_N];
long long power2[MAX_N];

void erathones() {
  for (int i = 2; i < MAX_N; i++) {
    isPrime[i] = true;
  }
  for (int i = 2; i * i < MAX_N; i++) {
    if (isPrime[i] == false) {
      continue;
    }
    for (int j = i * i; j < MAX_N; j += i) {
      isPrime[j] = false;
    }
  }
}

class PowerEquationEasy {
  public:
  int count(int n) {
    //erathones();
    power2[0] = 1LL;
    for (int i = 1; i < MAX_N; i++) {
      power2[i] = (1LL * power2[i - 1] * 2LL) % MOD;
    }
    long long res = (1LL * n * n) % MOD;
    long long ways = 1LL;
    for (int x = 2; x <= n; x++) {
      int value = x;
      int cnt = 0;
      for (int i = 2; i <= (int) sqrt(value); i++) {
        if (value == 1) {
          break;
        }
        while (value % i == 0) {
          cnt++;
          value /= i;
        }
      }
      if (value > 1) {
        cnt++;
      }
      (ways += power2[cnt - 1]) %= MOD;
    }
    cout << ways << endl;
    (res += (1LL * (n - 1) * ways) % MOD) %= MOD;
    int cnt = 0;
    for (int x = 2; x * x <= n; x++) {
      int curValue = x;
      while (curValue * x <= n) {
        cnt++;
        curValue *= x;
      }
    }
    (res += ((2LL * ways) % MOD * cnt) % MOD) %= MOD;
    return (int) res;
  }
};

PowerEquationEasy P;

int main () {
  cout << P.count(22306);
  return 0;
}