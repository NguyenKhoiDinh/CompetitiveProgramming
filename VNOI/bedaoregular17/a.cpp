#include <iostream>
#include <math.h>

int main () {
  long long L, R;
  std::cin >> L >> R; 
  long long d = R / L; 
  int ans = 1; 
  for (long long i = 2; i <= (long long) std::sqrt(d); i++) {
    while (d % i == 0) {
      ans++; 
      d /= i; 
    }  
  }
  if (d > 1) {
    ans++; 
  }
  std::cout << ans;
  return 0;
}