#include <iostream>

int main () {
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    std::cin >> n >> k; 
    if (k >= n - 1) {
      std::cout << ((n % 2 == 0) ? "Ayoub" : "Kilani") << std::endl; 
    }
    else {
      std::cout << "Kilani" << std::endl;
    }
  }
  return 0; 
}