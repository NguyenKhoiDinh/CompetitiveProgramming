#include <iostream>
#include <math.h> 
#include <cstring> 
int numTest; 
int n, m, k;
int f[102][10005];
int a[102];  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int calo = 0; calo <= m; calo++) {
        if (f[i][calo] == 0) {
          continue; 
        }
        f[i + 1][calo] += f[i][calo];
        f[i + 1][calo] = std::min(k, f[i + 1][calo]);
        if (calo + a[i + 1] <= m) {
          f[i + 1][calo + a[i + 1]] += f[i][calo];
          f[i + 1][calo + a[i + 1]] = std::min(k, f[i + 1][calo + a[i + 1]]); 
        } 
      }
    } 
    if (f[n][m] == k) {
      std::cout << "ENOUGH" << std::endl;
    }
    else {
      std::cout << f[n][m] << std::endl;
    }
  }
  return 0; 
}