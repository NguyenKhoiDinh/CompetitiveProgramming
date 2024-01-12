#include <iostream>

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    std::cout << (n % 2 == 0 ? "FireGhost" : "Lihwy") << std::endl; 
  }
  return 0;
}