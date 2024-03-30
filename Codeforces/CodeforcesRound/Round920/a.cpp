#include <iostream>
#include <algorithm>
#include <math.h>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int d = std::max(std::abs(x2 - x1), std::abs(y2 - y1)); 
    std::cout << d * d << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2; 
  }
  return 0; 
}