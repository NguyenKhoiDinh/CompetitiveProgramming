#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    int n;
    std::cin >> n;
    int currentYear = 0;
    for (int i = 1; i <= n; i++) {
      int x; 
      std::cin >> x; 
      currentYear = (currentYear / x + 1) * x; 
    } 
    std::cout << currentYear << std::endl;
  }
  return 0; 
}