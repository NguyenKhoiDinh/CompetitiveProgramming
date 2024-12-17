#include <iostream> 
#include <math.h> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int l, r;
    std::cin >> l >> r; 
    long long delta = 1LL + 8LL * r - 8LL * l; 
    long long x = (-1 + (long long) std::sqrt(delta)) / 2; 
    std::cout << x + 1 << std::endl; 
  }
  return 0; 
}                         
