#include <iostream>
#include <iomanip> 

int main () {
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int N;
    std::cin >> N; 
    std::cout << std::fixed << std::setprecision(12) << 1.0 / (N + 1) * 1000000000.000 << std::endl; 
  }
  return 0; 
}