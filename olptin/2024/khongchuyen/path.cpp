#include <iostream>
#include <math.h>  
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
void init() {
  fact[0] = 1LL; 
  inv_fact[0] = 1LL;
  for (int i = 1; i <= 200000; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod; 
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
}
long long f[1005][1005]; 
bool block[1005][1005]; 
int n, m, k; 
long long C(int n, int k) {
  long long ret = fact[n];
  (ret *= inv_fact[k]) %= mod;
  (ret *= inv_fact[n - k]) %= mod; 
  return ret; 
}

int main () {
  init(); 
  std::cin >> n >> m >> k; 
  for (int i = 1; i <= k; i++) {
    int x, y;
    std::cin >> x >> y;
    block[x][y] = true; 
  }
  int sizex = std::min(1000, n); 
  int sizey = std::min(1000, m);
  if (block[1][1] == false) {
    f[1][1] = 1LL; 
  } 
  for (int i = 1; i <= sizex; i++) {
    for (int j = 1; j <= sizey; j++) {
      if (f[i][j] == 0) {
        continue; 
      }
      if (i < sizex && block[i + 1][j] == false) {
        (f[i + 1][j] += f[i][j]) %= mod; 
      }
      if (j < sizey && block[i][j + 1] == false) {
        (f[i][j + 1] += f[i][j]) %= mod; 
      }
    }
  }
  if (n == sizex && m == sizey) {
    std::cout << f[n][m];
    return 0;
  }
  long long ans = 0LL; 
  for (int i = 1; i <= sizex; i++) {
    for (int j = 1; j <= sizey; j++) {
      if (i == sizex && i < n) {
        (ans += (f[i][j] * C(n - i - 1 + m - j, m - j)) % mod) %= mod;   
      }
      if (j == sizey && j < m) {
        (ans += (f[i][j] * C(n - i + m - j - 1, n - i)) % mod) %= mod; 
      }
    }
  }
  std::cout << ans;
  return 0; 
}           