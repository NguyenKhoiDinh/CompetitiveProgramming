#include <iostream>
int numTest, a, b, c;

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> a >> b >> c;
    if (c > 0) {
      std::cout << "CURVE UP";
    }
    else if (c < 0) {
      std::cout << "CURVE DOWN";
    }
    else {
      std::cout << "NO CURVE";
    }
    std::cout << std::endl;
  }
  return 0; 
}