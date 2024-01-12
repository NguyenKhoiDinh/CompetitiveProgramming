#include <iostream>
#include <vector>
const long long mod = 998244353LL; 
int n, m, k; 
std::vector <int> odd, even; 
int countPrimes[1000005]; 
bool isPrime[1000005];
int mu[1000005];  

void erathones() {
  for (int i = 1; i <= 1000000; i++) {
    isPrime[i] = true;   
  }
  isPrime[1] = false;
  mu[1] = 1; 
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 2 * i; j <= 1000000; j += i) {
      mu[j] -= mu[i]; 
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {   
      countPrimes[i]++; 
      for (int j = 2 * i; j <= 1000000; j += i) {
        countPrimes[j]++; 
        isPrime[j] = false; 
      }
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
  erathones();
  std::cin >> n >> m >> k; 
  for (int i = k; i <= m; i += k) {
    int d = i / k;
    if (mu[d] == 0) {
      continue;
    }
    if (countPrimes[d] % 2 == 0) {
      even.push_back(i); 
    }  
    else {
      odd.push_back(i); 
    }
  }
  long long ans = 0LL; 
  for (int i = 0; i < (int) even.size(); i++) {
    (ans += fastpow(m / even[i], n)) %= mod;   
  }
  for (int i = 0; i < (int) odd.size(); i++) {
    ans -= fastpow(m / odd[i], n);   
    (ans += mod) %= mod; 
  }
  std::cout << ans;
  return 0;
}                                                  