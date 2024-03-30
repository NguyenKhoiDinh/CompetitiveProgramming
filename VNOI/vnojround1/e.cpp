#include <iostream>
#include <math.h>
#include <algorithm>

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n; 
    std::cin >> n;
    long long ans = 0;
    for (long long x = 1; x <= n; x++) {
      for (long long y = x; y <= n; y++) {
        long long gcdx = std::__gcd(x, n);
        long long gcdy = std::__gcd(y, n); 
        if (gcdx * gcdy == std::__gcd(x * y, n)) {
          ans++; 
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}