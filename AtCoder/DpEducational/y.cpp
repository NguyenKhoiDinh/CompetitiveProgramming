#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>

using namespace std;
const int MAX_N = 100005;
const int MAX_BLOCK = 3005;
const long long MOD = 1000000007;
vector <pair <int, int> > block;
int n, H, W;
long long fact[MAX_N], invFact[MAX_N];
long long dp[MAX_BLOCK];

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

void DynamicProgramming() {
  int szBlock = (int) block.size();
  for (int i = 1; i <= szBlock; i++) {
    dp[i] = C(block[i - 1].first + block[i - 1].second - 2, block[i - 1].first - 1);
    for (int j = i - 1; j >= 1; j--) {
      if (block[j - 1].first <= block[i - 1].first && block[j - 1].second <= block[i - 1].second) {
        int x = block[i - 1].first - block[j - 1].first;
        int y = block[i - 1].second - block[j - 1].second;
        dp[i] -= (dp[j] * C(x + y, x)) % MOD;
        (dp[i] += MOD) %= MOD;
      }
    }
  }
  cout << dp[szBlock];
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  init();
  cin >> H >> W >> n;
  for (int i = 1; i <= n; i++) {
    int r, c;
    cin >> r >> c;
    block.push_back(make_pair(r, c));
  }
  block.push_back(make_pair(H, W));
  sort(block.begin(), block.end());
  DynamicProgramming();
  return 0;
}