#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 3005;
long long dp_in[MAX_N][MAX_N], dp_out[MAX_N][MAX_N];
long long cnt[MAX_N];

void computeDpIn(const string &s) {
  int n = (int) s.size();
  for (int l = n; l >= 1; l--) {
    for (int r = l; r <= n; r++) {
      (dp_in[l][r] += dp_in[l + 1][r]) %= MOD;
      (dp_in[l][r] += dp_in[l][r - 1]) %= MOD;
      (dp_in[l][r] += MOD - dp_in[l + 1][r - 1]) %= MOD;
      if (s[l - 1] == s[r - 1]) {
        (dp_in[l][r] += dp_in[l + 1][r - 1] + 1) %= MOD;
      }
    }
  }
  for (int l = 1; l <= n; l++) {
    for (int r = 1; r <= n; r++) {
      cout << dp_in[l][r] << "   ";
    }
    cout << endl;
  }
}

void computeDpOut(const string &s) {
  int n = (int) s.size();
  for (int l = 1; l <= n; l++) {
    for (int r = n; r >= l; r--) {
      (dp_out[l][r] += dp_out[l - 1][r]) %= MOD;
      (dp_out[l][r] += dp_out[l][r + 1]) %= MOD;
      (dp_out[l][r] += MOD - dp_out[l - 1][r + 1]) %= MOD;
      if (s[l - 1] == s[r - 1]) {
        (dp_out[l][r] += dp_out[l - 1][r + 1] + 1) %= MOD;
      }
    }
  }
  cout << "***************" << endl;
  for (int l = 1; l <= n; l++) {
    for (int r = 1; r <= n; r++) {
      cout << dp_out[l][r] << "   ";
    }
    cout << endl;
  }
}

class PalindromicSubseq {
  public:
  int solve(string s) {
    int n = (int) s.size();
    computeDpIn(s);
    computeDpOut(s);
    for (int i = 1; i <= n; i++) {
      cnt[i] = dp_out[i - 1][i + 1];
    }
    for (int l = 1; l <= n; l++) {
      for (int r = l + 1; r <= n; r++) {
        if (s[l - 1] == s[r - 1]) {
          (cnt[l] += ((dp_in[l + 1][r - 1] + 1) * (dp_out[l - 1][r + 1] + 1) % MOD)) %= MOD;
          (cnt[r] += ((dp_in[l + 1][r - 1] + 1) * (dp_out[l - 1][r + 1] + 1) % MOD)) %= MOD;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << cnt[i] << ' ';
    }
    cout << endl;
    long long ans = 0LL;
    for (int i = 1; i <= n; i++) {
      long long res = (cnt[i] + 1) % MOD;
      (res *= i) %= MOD;
      ans ^= res;
    }
    return (int) ans;
  }
};

PalindromicSubseq P;

int main () {
  cout << P.solve("aaba");
  return 0;
}