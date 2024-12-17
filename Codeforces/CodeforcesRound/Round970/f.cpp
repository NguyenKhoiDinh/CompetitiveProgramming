#include <iostream> 
const long long mod = 1000000007LL; 
int numTest; 
long long fastpow(const long long &x, const long long n) {
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
int n;
long long a[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    long long sum = 0LL;
    long long sumSquare = 0LL; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      sum += a[i];
      (sumSquare += (a[i] * a[i]) % mod) %= mod; 
    }
    sumSquare %= mod; 
    sum %= mod; 
    (sum *= sum) %= mod; 
    sum -= sumSquare; 
    if (sum < 0) {
      sum += mod; 
    }
    sum %= mod;                                    
    (sum *= fastpow(2LL, mod - 2)) %= mod;
    long long nume = 1LL * n * (n - 1) / 2;  
    nume %= mod; 
    nume = fastpow(nume, mod - 2);
    (sum *= nume) %= mod;
    std::cout << sum << std::endl; 
  }
  return 0; 
}