#include <iostream>
#include <math.h> 
int numTest; 
long long l1, r1, l2, r2;
long long k;  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> k >> l1 >> r1 >> l2 >> r2;
    long long value = 1;
    long long ans = 0LL; 
    while (value <= 1000000000) {
      long long L = value * l1;
      long long R = value * r1; 
      L = std::max(L, l2);
      R = std::min(R, r2); 
      if (L <= R) {
        ans += (R / value) - (L - 1) / value;   
      }
      value *= k; 
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}
