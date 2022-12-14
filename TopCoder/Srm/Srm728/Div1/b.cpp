#include <bits/stdc++.h>

using namespace std;
const long long MOD = 998244353;
const int MAX_N = 303;
long long dp[2 * MAX_N][MAX_N];
long long inv_fact[MAX_N];

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

void init() {
  inv_fact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    inv_fact[i] = (inv_fact[i - 1] * POW(i, MOD - 2)) % MOD;
  }
}

class IncreasingSequences {
  public:
  int count(vector <int> L, vector <int> R) {
    init();
    int n = (int) L.size();
    vector <int> v;
    for (int i = 0; i < n; i++) {
      v.push_back(L[i] - 1);
      v.push_back(R[i]);
    }
    sort(v.begin(), v.end());
    vector <pair <int, int> > listSegment;
    for (int i = 1; i < (int) v.size(); i++) {
      if (v[i] > v[i - 1]) {
        listSegment.push_back(make_pair(v[i - 1] + 1, v[i]));
      }
    }
    int sizeList = (int) listSegment.size();
    dp[0][0] = 1LL;
    for (int i = 0; i < sizeList; i++) {
      for (int j = 0; j <= n; j++) {
        if (dp[i][j] == 0) {
          continue;
        }
        long long cur = dp[i][j];
        (dp[i + 1][j] += cur) %= MOD;
        int k = j + 1;
        int l = listSegment[i].first;
        int r = listSegment[i].second;
        int len = r - l + 1;
        long long mul = cur;
        int val = len;
        while (k <= n) {
          int x = k - j;
          if (L[k - 1] <= l && r <= R[k - 1] && x <= len) {
            (mul *= val) %= MOD;
            val--;
            (dp[i + 1][k] += (mul * inv_fact[x]) % MOD) %= MOD;
            k++;
          }
          else {
            break;
          }
        }
      }
    }
    return (int) dp[sizeList][n];
  }
};

IncreasingSequences I;

int main () {
  cout << I.count({4, 46, 46, 35, 20, 77, 20},
{41, 65, 84, 90, 49, 86, 88});
  return 0;
}