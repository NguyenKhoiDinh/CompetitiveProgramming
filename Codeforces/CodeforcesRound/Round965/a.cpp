#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int xc, yc, k;
    std::cin >> xc >> yc >> k; 
    for (int i = 1; i <= k / 2; i++) {
      std::cout << xc - i << ' ' << yc - i << std::endl;
      std::cout << xc + i << ' ' << yc + i << std::endl; 
    }
    if (k % 2 == 1) {
      std::cout << xc << ' ' << yc << std::endl;
    }
  }
  return 0; 
}