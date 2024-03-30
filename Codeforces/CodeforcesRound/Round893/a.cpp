#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c; 
    std::cin >> a >> b >> c; 
    if (c % 2 == 1) {
      a++; 
    }
    std::cout << (a > b ? "First" : "Second") << std::endl;
  }
  return 0; 
}