#include <iostream>
#include <math.h>
#include <algorithm>

int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long a, b;
    std::cin >> a >> b; 
    std::cout << a * b / std::__gcd(a, b) << std::endl;
  }
  return 0; 
}