#include <iostream>
#include <math.h> 

int main () {
  long long n, d, s;
  std::cin >> n >> d >> s; 
  n /= s;
  d /= s; 
  long long lim = std::min(std::max(2LL * d, d + 1), n);
  if (lim % 2 == 0) {
    std::cout << lim * s; 
  } 
  else {
    bool ok = false;
    for (long long x = 1; x * x <= lim; x++) {
      if (lim % x == 0) {
        if (lim - x <= d) {
          ok = true;
          break;   
        }
        if (x > 1 && lim - (lim / x) <= d) {
          ok = true;
          break; 
        }
      }
    }
    std::cout << (ok == true ? lim * s : (lim - 1) * s); 
  }
  return 0; 
}