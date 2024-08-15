#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int L, v, l, r;
    std::cin >> L >> v >> l >> r;
    std::cout << L / v - (r / v - (l - 1) / v) << std::endl;         
  }
  return 0; 
}