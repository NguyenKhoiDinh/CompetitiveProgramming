#include <iostream> 
#include <map> 
int numTest; 
long long a, b, s, p, v; 
long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= p; 
  if (n % 2 == 1) {
    (ret *= x) %= p; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> a >> b >> s >> p >> v;
    if (a == 1) {
      long long bn = (v - s + p) % p; 
      long long n = bn; 
      (n *= fastpow(b, p - 2)) %= p; 
      std::cout << n << std::endl; 
      continue; 
    }  
    long long left = (s * (a - 1) % p + b) % p;
    long long right = (v * (a - 1) % p + b) % p; 
    if (left == 0 && right == 0) {
      std::cout << 0 << std::endl; 
    }
    else if (left == 0 && right != 0) {
      std::cout << "IMPOSSIBLE" << std::endl; 
    }
    else {
      const long long m = 47000; 
      long long y = (v * (a - 1) % p + b) % p; 
      (y *= fastpow((s * (a - 1) % p + b) % p, p - 2)) %= p;
      std::map <long long, int> f; 
      f[1] = 0; 
      long long mul = 1LL; 
      for (int i = 1; i < m; i++) {
        (mul *= a) %= p; 
        if (f.find(mul) == f.end()) {
          f[mul] = i; 
        }
      }
      long long ans = -1; 
      long long mula = fastpow(a, m); 
      mula = fastpow(mula, p - 2); 
      for (int i = 0; i < m; i++) {
        if (f.find(y) != f.end()) {
          ans = (long long) i * m + f[y];
          break;   
        }
        (y *= mula) %= p; 
      }
      if (ans == -1) {
        std::cout << "IMPOSSIBLE" << std::endl; 
      }
      else {
        std::cout << ans << std::endl;
      }
    }
  }
  return 0; 
}