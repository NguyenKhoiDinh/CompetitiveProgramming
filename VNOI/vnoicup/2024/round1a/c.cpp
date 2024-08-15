#include <iostream>

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x;
    std::cin >> x;
    int i = 1;  
    int value;
    while (true) {
      if ((1 << i) - 2 <= x) {
        i++; 
      }
      else {
        i--; 
        break; 
      }
    }
    std::cout << i << std::endl; 
    int mask = (1 << i) - 1; 
    for (int j = 0; j < i; j++) {
      std::cout << (mask ^ (1 << j)) << ' ';
    }
    std::cout << std::endl;
  }
  return 0; 
}