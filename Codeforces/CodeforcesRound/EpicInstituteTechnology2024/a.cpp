#include <iostream>
#include <math.h> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::cout << std::min(n, k) * std::min(m, k) << std::endl; 
  }
  return 0; 
}