#include <iostream>
#include <math.h> 
int numTest; 
int a[200005], b[200005];
int n, m; 
long long suf[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i]; 
    }
    suf[n + 1] = 0LL;
    for (int i = n; i >= 1; i--) {
      suf[i] = suf[i + 1] + std::min(a[i], b[i]); 
    }
    long long ans = 200000000000007LL; 
    for (int i = 1; i <= m; i++) {
      ans = std::min(ans, a[i] + suf[i + 1]);
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}