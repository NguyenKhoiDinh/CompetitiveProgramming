#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, y;
    std::cin >> x >> y;
    std::cout << std::min(x, y) << ' ' << std::max(x, y) << std::endl;
  }
  return 0; 
}