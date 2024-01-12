#include <iostream>
#include <math.h>
int numTest; 
long long t, k, n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> t >> k >> n;
    if (n < t) {
      std::cout << 0 << std::endl;
      continue;
    }
    std::cout << (n - t) / k + 1 << std::endl;
  }
  return 0; 
}