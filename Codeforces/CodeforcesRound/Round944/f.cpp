#include <iostream>
#include <math.h>
#include <algorithm>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long r;
    std::cin >> r;
    long long ans = 0LL;
    for (long long x = 0; x <= 2 * r; x++) {
      if (r * r < x * x) {
        break;
      }
      long long lo = (long long) sqrt(r * r - x * x); 
      if (lo * lo != r * r - x * x) {
        lo++; 
      }
      long long hi = (long long) sqrt(r * r + 2LL * r + 1 - x * x);
      if (hi * hi == r * r + 2LL * r + 1 - x * x) {
        hi--; 
      } 
      if (lo <= hi) {
        long long numb = 2LL * (hi - lo + 1); 
        if (lo == 0) {
          numb--; 
        } 
        if (x > 0) {
          numb *= 2LL; 
        }
        ans += numb;
      }
    }  
    std::cout << ans << std::endl;
  }
  return 0; 
}