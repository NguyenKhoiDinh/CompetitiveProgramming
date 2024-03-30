#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    int n;
    std::cin >> n;
    int p = 1;
    while (2 * p <= n) {
      p *= 2;
    } 
    std::cout << p << std::endl;
  }
  return 0; 
}