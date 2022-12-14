#include <iostream> 
#include <math.h>                           
#include <cstring> 
int numTest; 
int a[205][205]; 
int sum1[205][205], sum2[205][205]; 
int n, m;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cin >> a[i][j]; 
      }
    }
    std::memset(sum1, 0, sizeof(sum1));
    std::memset(sum2, 0, sizeof(sum2));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum1[i][j] = sum1[i - 1][j - 1] + a[i][j]; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = m; j >= 1; j--) {
        sum2[i][j] = sum2[i - 1][j + 1] + a[i][j]; 
      }
    }
    int ans = -1; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int total = 0; 
        int distance = std::min(n - i, m - j); 
        total += sum1[i + distance][j + distance]; 
        distance = std::min(n - i, j - 1); 
        total += sum2[i + distance][j - distance]; 
        total -= a[i][j]; 
        ans = std::max(ans, total); 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}