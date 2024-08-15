#include <iostream>

int main () {
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n; 
    std::cin >> n; 
    for (int b = 0; b < 30; b++) {
      if ((n & (1 << b)) > 0) {
        std::cout << b + 1 << std::endl;
        break;
      }
    }
  }
  return 0; 
}