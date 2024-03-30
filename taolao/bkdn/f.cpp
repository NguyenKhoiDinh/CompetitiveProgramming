#include <iostream>
#include <math.h>
#include <string>  
#include <vector>
int f[55][55][4];
std::vector <std::string> a;
int n, m, k;   

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> n >> m >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int add = 0; add <= k; add++) {
        f[i][j][add] = -1; 
      }
    }
  }
  f[1][1][0] = 0; 
  for (int add = 0; add <= k; add++) {  
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (f[i][j][add] == -1) {
          continue; 
        }
        if (j + 1 <= m && a[i - 1][j] != '#') {
          f[i][j + 1][add] = std::max(f[i][j + 1][add], f[i][j][add] + (a[i - 1][j] == '.' ? 0 : a[i - 1][j] - '0')); 
        }
        if (i + 1 <= n && a[i][j - 1] != '#') {
          f[i + 1][j][add] = std::max(f[i + 1][j][add], f[i][j][add] + (a[i][j - 1] == '.' ? 0 : a[i][j - 1] - '0')); 
        }
        if (add + 1 <= k && i - 1 >= 1 && a[i - 2][j - 1] != '#') {
          f[i - 1][j][add + 1] = std::max(f[i - 1][j][add + 1], f[i][j][add] + (a[i - 2][j - 1] == '.' ? 0 : a[i - 2][j - 1] - '0'));
        }
        if (add + 1 <= k && j - 1 >= 1 && a[i - 1][j - 2] != '#') {
          f[i][j - 1][add + 1] = std::max(f[i][j - 1][add + 1], f[i][j][add] + (a[i - 1][j - 2] == '.' ? 0 : a[i - 1][j - 2] - '0'));
        }
      }
    }
  }
  int ans = -1; 
  for (int add = 0; add <= k; add++) {
    ans = std::max(ans, f[n][m][add]); 
  }
  std::cout << ans; 
  return 0; 
}