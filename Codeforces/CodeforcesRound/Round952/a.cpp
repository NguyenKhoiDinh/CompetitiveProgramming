#include <iostream>
#include <string>
#include <algorithm>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string a, b;
    std::cin >> a >> b;
    std::swap(a[0], b[0]); 
    std::cout << a << ' ' << b << std::endl;
  }
  return 0; 
}