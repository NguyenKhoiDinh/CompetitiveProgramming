#include <iostream> 
#include <algorithm>
#include <math.h> 
int n;
long long a[200005]; 
long long f(long long x) {
  long long need = 2LL * x - a[1]; 
  long long total = 0LL; 
  for (int i = 2; i <= n; i++) {
    total += std::max(0LL, a[i] - x);   
  }
  return std::min(need, total);
}

int main () {
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }  
    long long lo = (a[1] + 1) / 2; 
    long long hi = 1000000007;
    long long ans = 0LL; 
    while (lo <= hi) {
      int u = (2 * lo + hi) / 3; 
      int v = (lo + 2 * hi) / 3; 
      long long fu = f(u);
      long long fv = f(v);                          
      if (fu >= fv) {
        ans = std::max(ans, fu); 
        hi = v - 1; 
      }
      else {
        ans = std::max(ans, fv); 
        lo = u + 1; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}