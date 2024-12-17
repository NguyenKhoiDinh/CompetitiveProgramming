#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353LL;
int n, m; 
long long f[505][505], ways[505][505]; 
void init() {
  ways[0][0] = 1LL; 
  for (int i = 0; i < 500; i++) {
    for (int j = 0; j <= i; j++) {
      if (ways[i][j] == 0) {
        continue; 
      }
      (ways[i + 1][j + 1] += ways[i][j]) %= mod;
      if (j > 0) {
        (ways[i + 1][j - 1] += ways[i][j]) %= mod; 
      }
    }
  }
}

int main () {     
  init(); 
  cin >> n >> m; 
  for (int i = 0; i <= m; i += 2) {
    f[1][i] = ways[m][i];                          
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= m; j += 2) {
      if (f[i][j] == 0) {
        continue; 
      }
      for (int x = 0; x <= j; x += 2) {
        long long mul = ways[m][x];
        (f[i + 1][j - x] += (mul * f[i][j]) % mod) %= mod;   
      }
    }  
  }                          
  cout << f[n][0]; 
  return 0; 
}