#include <iostream> 
#include <algorithm> 
#include <math.h>
int numTest; 
int n, k;
int a[200005]; 
long long suffix[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    long long sum = 0LL; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      sum += a[i]; 
    }
    std::sort(a + 1, a + n + 1); 
    suffix[n + 1] = 0LL; 
    for (int i = n; i >= 1; i--) {
      suffix[i] = suffix[i + 1] + a[i]; 
    }
    long long prefix = 0LL; 
    long long ans = 0LL; 
    for (int i = 0; i <= n; i += 2) {
      if (i / 2 <= k && (n - (k - i / 2) + 1 > i)) {
        if (i > 0) {
          prefix += a[i] + a[i - 1]; 
        }
        ans = std::max(ans, sum - (prefix + suffix[n - (k - i / 2) + 1]));
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}