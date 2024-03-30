#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a < b && b > c) {
      std::cout << "PEAK";
    }
    else if (a < b && b < c) {
      std::cout << "STAIR";
    }
    else {
      std::cout << "NONE";
    }
    std::cout << std::endl;
  }
  return 0; 
}