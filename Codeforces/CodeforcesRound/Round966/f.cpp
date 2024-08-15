#include <iostream> 
#include <math.h>
const int inf = 1000000007;  
int numTest; 
int f[1005][105];
int value[1005][105];
int n, k;
int a[1005], b[1005];   

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i] >> b[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        f[i][j] = inf; 
        value[i][j] = inf; 
      }  
    }
    for (int i = 1; i <= n; i++) {
      for (int x = 0; x <= a[i]; x++) {
        for (int y = 0; y <= b[i]; y++) {
          int numb = x * b[i] + y * a[i] - x * y; 
          if (x + y <= k) {
            value[i][x + y] = std::min(value[i][x + y], numb); 
          }
        }
      }
    }
    f[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (f[i][j] == inf) {
          continue; 
        }
        for (int x = 0; x <= k - j; x++) {
          if (value[i + 1][x] != inf) {
            f[i + 1][j + x] = std::min(f[i + 1][j + x], f[i][j] + value[i + 1][x]); 
          }   
        }
      }
    }
    std::cout << (f[n][k] == inf ? -1 : f[n][k]) << std::endl; 
  }
  return 0; 
}