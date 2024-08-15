#include <iostream>

int main () {
  int numTest; 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    std::cin >> n >> k;
    std::cout << 1 + (n - 1) * k << std::endl;
  }
  return 0; 
}