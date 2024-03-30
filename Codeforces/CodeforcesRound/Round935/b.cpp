#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long a, b, m;
    std::cin >> a >> b >> m;
    std::cout << (m / a + 1) + (m / b + 1) << std::endl;
  }
  return 0; 
}