#include <iostream>
const long long mod = 998244353LL;
long long f[20][20]; 
int n, p[20]; 
long long power2[20]; 
 
int main () {
  power2[0] = 1LL;
  for (int i = 1; i < 20; i++) {
    power2[i] = (power2[i - 1] * 2LL) % mod; 
  }
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  f[1][1] = 1LL; 
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      if (f[i][j] == 0) {
        continue; 
      }
      for (int h = 2; h <= j + 1; h++) {
        f[i + 1][h] += (f[i][j] * power2[h - 2]) % mod;
        f[i + 1][h] %= mod; 
      }
    }
  } 
  long long ans = 0LL;
  for (int j = 1; j <= n; j++) {
    (ans += f[n][j]) %= mod;
  }
  std::cout << ans;
  return 0; 
}