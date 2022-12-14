#include <iostream>
#include <math.h> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int firstTime = std::abs(a - 1); 
    int secondTime = std::abs(b - c) + std::abs(c - 1);
    if (firstTime < secondTime) {
      std::cout << 1;
    }
    else if (firstTime > secondTime) {
      std::cout << 2;
    }
    else {
      std::cout << 3; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}