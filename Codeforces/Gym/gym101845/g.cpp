#include <iostream>
#include <string> 
const long long mod = 1000000007LL; 
long long fastpow(const long long &x, long long n) {
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
int n, m;
long long inv[1005]; 
std::string s; 
struct prob {
  long long p, q; 
};
long long f[5005][5005]; 
prob c[27]; 

int main () {
  for (int i = 1; i <= 1000; i++) {
    inv[i] = fastpow(i, mod - 2); 
  }
  std::cin >> n >> m; 
  std::cin >> s;
  for (int i = 1; i <= 26; i++) {
    std::cin >> c[i].p >> c[i].q; 
  } 
  f[0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      if (f[i][j] == 0) {
        continue; 
      }
      if (j == m) {
        (f[i + 1][j] += f[i][j]) %= mod; 
      }
      if (j < m) {
        long long p = c[s[j] - 'a' + 1].p;
        long long q = c[s[j] - 'a' + 1].q; 
        (f[i + 1][j] += ((f[i][j] * (q - p)) % mod * inv[q]) % mod) %= mod; 
        (f[i + 1][j + 1] += ((f[i][j] * p) % mod * inv[q]) % mod) %= mod; 
      }
    }  
  }
  std::cout << f[n][m];
  return 0; 
}