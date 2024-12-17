#include <iostream>
int numTest;
int n;  

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cout << n - 1 << std::endl;
  }
  return 0;
}