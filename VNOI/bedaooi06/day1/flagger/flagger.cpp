#include <iostream>
#include <math.h>
#include <vector>
#include <utility>   
#include <algorithm>
const long long mod = 1000000007LL;
int f[5005][2505];
int g[5005][5005];
int C[5005][5005];
long long fact[5005]; 
int n, m;   
                         
int main () {
  freopen("flagger.inp", "r", stdin);
  freopen("flagger.out", "w", stdout); 
  std::cin >> n >> m;
  if (n < m) {
    std::swap(n, m); 
  }
  fact[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod; 
  }
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1LL;
    C[i][i] = 1LL; 
  }  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod; 
    }
  }
  for (int j = 0; j <= m; j++) {
    g[0][j] = 1LL; 
  }              
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      g[i][j] = g[i - 1][j];
      if (j > 0) {
        (g[i][j] += (4LL * j * g[i - 1][j - 1]) % mod) %= mod;
      }  
    }
  }
  f[0][0] = 1LL;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (f[i][j] == 0) {
        continue; 
      }
      (f[i + 1][j + 1] += f[i][j]) %= mod;
      if (2 * j - i > 0) {
        (f[i + 1][j] += (1LL * (2 * j - i) * f[i][j]) % mod) %= mod;   
      } 
    }
  }                                 
  long long ans = 0LL; 
  for (int x = 0; x <= n; x++) {
    if (2 * x > m) {
      continue; 
    }
    for (int y = 0; y <= m - 2 * x; y++) {
      if (2 * y + x > n) {
        continue; 
      }                                          
      long long mul = 1LL; 
      (mul *= C[n][x]) %= mod; 
      (mul *= f[2 * x][x]) %= mod; 
      (mul *= C[m][2 * x]) %= mod; 
      (mul *= C[m - 2 * x][y]) %= mod; 
      (mul *= f[2 * y][y]) %= mod; 
      (mul *= C[n - x][2 * y]) %= mod; 
      (mul *= g[n - x - 2 * y][m - y - 2 * x]) %= mod; 
      (ans += mul) %= mod; 
    }
  }
  ans--; 
  if (ans < 0) {
    ans += mod; 
  }
  std::cout << ans; 
  return 0; 
}