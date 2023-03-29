#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
const long long mod = 1000000007;
std::vector <std::pair <int, int> > block;
int n, H, W;
long long fact[200005], invFact[200005];
long long dp[3005];

long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL;
  }
  long long ret = fastpow(x, n / 2);
  (ret *= ret) %= mod;
  if (n % 2 == 1) {
    (ret *= x) %= mod;
  }
  return ret;
}

void init() {
  fact[0] = 1LL;
  invFact[0] = 1LL;
  for (int i = 1; i < 200005; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod;
    invFact[i] = fastpow(fact[i], mod - 2);
  }
}

long long C(int n, int k) {
  long long res = fact[n];
  (res *= invFact[k]) %= mod;
  (res *= invFact[n - k]) %= mod;
  return res;
}

void dynamicProgramming() {
  int szBlock = (int) block.size();
  for (int i = 1; i <= szBlock; i++) {
    dp[i] = C(block[i - 1].first + block[i - 1].second - 2, block[i - 1].first - 1);
    for (int j = i - 1; j >= 1; j--) {
      if (block[j - 1].first <= block[i - 1].first && block[j - 1].second <= block[i - 1].second) {
        int x = block[i - 1].first - block[j - 1].first;
        int y = block[i - 1].second - block[j - 1].second;
        dp[i] -= (dp[j] * C(x + y, x)) % mod;
        (dp[i] += mod) %= mod;
      }
    }
  }
  std::cout << dp[szBlock];
}

int main () {
  init();
  std::cin >> H >> W >> n;
  for (int i = 1; i <= n; i++) {
    int r, c;
    std::cin >> r >> c;
    block.push_back(std::make_pair(r, c));
  }
  block.push_back(std::make_pair(H, W));
  std::sort(block.begin(), block.end());
  dynamicProgramming();
  return 0;
}