#include <iostream>
const int mod = 1000000007; 
int f[2][10005][2]; 
int n, m, k; 
int cur = 0; 

int main () {
  std::cin >> n >> m >> k; 
  for (int j = 1; j <= m; j++) {
    int x = 1; 
    int y = j; 
    while (x <= n && y >= 1) {
      cur = 1 - cur; 
      if (x == 1 && y == 1) {
        f[cur][1][1] = 1; 
      }    
      else if (x == 1) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod;
          f[cur][i][1] = (f[1 - cur][i - 1][0] + f[1 - cur][i - 1][1]) % mod;  
        }
      }
      else if (y == 1) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = 0; 
          f[cur][i][1] = (f[1 - cur][i - 1][0] + f[1 - cur][i][1]) % mod; 
        }
      }
      else if (x == n) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod; 
          f[cur][i][1] = 0; 
        }
      }
      else if (y == m) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod;
          f[cur][i][1] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod; 
        }
      }
      else {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod; 
          f[cur][i][1] = (f[1 - cur][i - 1][0] + f[1 - cur][i][1]) % mod; 
        }
      }
      x++;
      y--; 
    }
  }
  for (int i = 2; i <= n; i++) {
    int x = i; 
    int y = m;
    while (x <= n && y >= 1) {
      cur = 1 - cur; 
      if (x == 1 && y == 1) {
        f[cur][i][0] = 1;
        f[cur][i][1] = 1; 
      }
      else if (x == 1) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod;
          f[cur][i][1] = (f[1 - cur][i - 1][0] + f[1 - cur][i - 1][1]) % mod;  
        }
      }
      else if (y == 1) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = 0; 
          f[cur][i][1] = (f[1 - cur][i - 1][0] + f[1 - cur][i][1]) % mod; 
        }
      }
      else if (x == n) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod; 
          f[cur][i][1] = 0; 
        }
      }
      else if (y == m) {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod;
          f[cur][i][1] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod; 
        }
      }
      else {
        for (int i = 1; i <= k; i++) {
          f[cur][i][0] = (f[1 - cur][i][0] + f[1 - cur][i][1]) % mod; 
          f[cur][i][1] = (f[1 - cur][i - 1][0] + f[1 - cur][i][1]) % mod; 
        }
      }
      x++;
      y--; 
    } 
  }
  if (n == 1 || m == 1) {
    if (k == 1) {
      std::cout << 1 << std::endl; 
    }
    else {
      std::cout << 0 << std::endl; 
    }
  }
  else {
    std::cout << f[cur][k][0];
  }
  return 0; 
}