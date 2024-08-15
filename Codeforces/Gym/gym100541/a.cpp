#include <iostream>
#include <math.h>
int numTest; 
long long p[105];
int n;
long long w; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> w;
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i]; 
    }
    long long ans = 0LL;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (p[i] < p[j]) {
          long long stock = w / p[i]; 
          ans = std::max(ans, stock * (p[j] - p[i])); 
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}