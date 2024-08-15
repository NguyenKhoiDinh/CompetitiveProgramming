#include <iostream>
#include <math.h>
#include <string> 
int numTest; 
int f[105][105];
std::string a, b;

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> a >> b;
    int n = (int) a.size();
    int m = (int) b.size();
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        f[i][j] = 10005; 
      }
    } 
    f[0][0] = 0; 
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (f[i][j] == 10005) {
          continue; 
        }  
        if (i == 0) {
          f[i + 1][j] = std::min(f[i + 1][j], f[i][j] + 1); 
          if (j < m && a[i] == b[j]) {
            f[i + 1][j + 1] = std::min(f[i + 1][j + 1], f[i][j] + 1); 
          }
          if (j < m) {
            f[i][j + 1] = std::min(f[i][j + 1], f[i][j] + 1); 
          }
        }
        else if (i == n) {
          if (j < m) {
            f[i][j + 1] = std::min(f[i][j + 1], f[i][j] + 1); 
          }
        }
        else {
          f[i + 1][j] = std::min(f[i + 1][j], f[i][j] + 1); 
          if (j < m && a[i] == b[j]) {
            f[i + 1][j + 1] = std::min(f[i + 1][j + 1], f[i][j] + 1); 
          }
        }
      }
    }
    std::cout << f[n][m] << std::endl;
  }
  return 0; 
}