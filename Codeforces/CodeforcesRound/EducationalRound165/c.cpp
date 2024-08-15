#include <iostream>
#include <math.h>
const long long inf = 1000000000000007LL; 
int numTest; 
long long f[300005][12];
int n, k;
int a[300005];  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        f[i][j] = inf; 
      }
    }
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (f[i][j] == inf) {
          continue; 
        }
        int minValue = 1000000007; 
        for (int x = i + 1; x <= std::min(n, i + k - j + 1); x++) {
          minValue = std::min(minValue, a[x]); 
          f[x][j + x - i - 1] = std::min(f[x][j + x - i - 1], f[i][j] + 1LL * (x - i) * minValue);
        }
      }
    }
    long long ans = inf; 
    for (int j = 0; j <= k; j++) {
      ans = std::min(ans, f[n][j]); 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}