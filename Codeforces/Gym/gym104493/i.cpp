#include <iostream>
const long long mod = 1000000007LL; 
long long fact[2000005], inv_fact[2000005];
long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2);
  ret = (ret * ret) % mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

void init() {
  fact[0] = 1LL;
  inv_fact[0] = 1LL; 
  for (int i = 1; i <= 2000000; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
}

long long C(int n, int k) {
  long long ret = fact[n];
  (ret *= inv_fact[n - k]) %= mod;
  (ret *= inv_fact[k]) %= mod;
  return ret; 
}
long long a0, a1, b0, b1; 

long long calc(int n, int groups) {
  return C(n + groups - 1, groups - 1); 
}

int main () {
  init(); 
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
  long long ans = 0LL; 
  long long n0, n1;
  std::cin >> n0 >> n1; 
  std::cin >> a0 >> b0 >> a1 >> b1;     
  for (long long groups = 1; groups * b0 <= n0; groups++) {
    long long groups0 = groups;
    long long groups1 = groups;
    if (1LL * groups1 * b1 <= n1) {
      (ans += (2LL * calc(n0 - groups0 * b0, groups0 + 1) * calc(n1 - groups1 * b1, groups1 + 1)) % mod) %= mod;
    }
    if (groups > 1) {                 
      groups1 = groups - 1;
      if (1LL * groups1 * b1 <= n1) { 
        (ans += (calc(n0 - groups0 * b0, groups0 + 1) * calc(n1 - groups1 * b1, groups1 + 1)) % mod) %= mod;
      }
    }  
    groups1 = groups + 1; 
    if (1LL * groups1 * b1 <= n1) {
      (ans += (calc(n0 - groups0 * b0, groups0 + 1) * calc(n1 - groups1 * b1, groups1 + 1)) % mod) %= mod;
    }
  }
  std::cout << ans << std::endl;
  }
  return 0; 
}