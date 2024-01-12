#include <iostream>
#include <vector>
long long mod; 
int numTest; 
int l, r; 
bool isPrime[1000005];
std::vector <int> listPrime; 
int power[1000005]; 

void erathones() {
  for (int i = 1; i <= 1000000; i++) {
    isPrime[i] = true;   
  }
  isPrime[1] = false;
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {   
      for (int j = 2 * i; j <= 1000000; j += i) {
        isPrime[j] = false; 
      }
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      listPrime.push_back(i);
    }
  }
}

int calc(int n, int p) {
  int ret = 0; 
  for (int i = p; i <= n; i *= p) {
    ret += n / i; 
  }
  return ret; 
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

void solve(int l, int r) {
  long long ans = 1LL; 
  for (int i = 0; i < (int) listPrime.size(); i++) {
    int p = listPrime[i];
    if (p > r) {
      break; 
    }
    power[p] = calc(r, p) - calc(l - 1, p);  
    if (power[p] > 0) {
      power[p]--;
      (ans *= fastpow(p, power[p])) %= mod;
      (ans *= (long long) (p - 1)) %= mod;   
    }
  }
  std::cout << ans << std::endl; 
}

int main () {
  erathones();
  std::cin >> mod;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> l >> r; 
    for (int i = 1; i <= r; i++) {
      power[i] = 0; 
    }
    solve(l, r); 
  }
  return 0;
}