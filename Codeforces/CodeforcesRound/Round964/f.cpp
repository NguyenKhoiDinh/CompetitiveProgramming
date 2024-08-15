#include <iostream> 
int numTest; 
const long long mod = 1000000007LL; 
long long fact[200005], inv_fact[200005];
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
long long C(int n, int k) {
  long long ret = fact[n];
  (ret *= inv_fact[k]) %= mod;
  (ret *= inv_fact[n - k]) %= mod;
  return ret;  
}

int main () {
  fact[0] = 1LL;
  inv_fact[0] = 1LL;
  for (int i = 1; i <= 200000; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod; 
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    std::cin >> n >> k;
    int numb0 = 0;
    int numb1 = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x; 
      if (x == 0) {
        numb0++; 
      }
      else {
        numb1++; 
      }
    }
    long long ans = 0LL; 
    int half = (k + 1) / 2;
    for (int n1 = half; n1 <= k; n1++) {
      int n0 = k - n1; 
      if (n1 <= numb1 && n0 <= numb0) {
        long long mul = C(numb1, n1);
        (mul *= C(numb0, n0)) %= mod;
        (ans += mul) %= mod;  
      }
    }     
    std::cout << ans << std::endl;
  }
  return 0; 
}