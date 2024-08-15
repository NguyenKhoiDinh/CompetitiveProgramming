#include <iostream>
#include <vector> 
int n, numTest;
long long mod;
long long f[1000005][2];  
bool isPrime[1000005]; 
std::vector <int> listPrimes; 
void init() {
  for (int i = 2; i <= 1000000; i++) {
    isPrime[i] = true; 
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      for (int j = 2 * i; j <= 1000000; j += i) {
        isPrime[j] = false; 
      }
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      listPrimes.push_back(i); 
    }
  }
}
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

int main () {
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> mod;
    f[1][0] = 1LL; 
    f[1][1] = 1LL; 
    f[2][0] = 2LL;
    f[2][1] = 1LL;  
    for (int i = 3; i <= n; i++) {
      f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
      f[i][1] = (f[i - 2][0] + f[i - 2][1]) % mod; 
    }
    long long ans = (f[n][0] + f[n][1]) % mod; 
    if (n % 2 == 0) {
      ans -= (1 + n / 2) % mod;
      int N = n; 
      int half = N / 2; 
      ans += mod;
      ans %= mod;  
      long long mul = 1LL; 
      for (int i = 0; i < (int) listPrimes.size(); i++) {
        int p = listPrimes[i];
        long long power = 0;
        long long tmp = p;
        while (tmp <= N) {
          power += N / tmp;
          tmp *= p; 
        }
        tmp = p;
        while (tmp <= half) {
          power -= 2 * (half / tmp); 
          tmp *= p; 
        }
        (mul *= fastpow(p, power)) %= mod;        
      }
      (ans += mul) %= mod; 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}