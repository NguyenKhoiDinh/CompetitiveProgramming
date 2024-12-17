#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n; 
    if (n <= 4) {
      std::cout << -1 << std::endl; 
    }
    else {
      for (int i = 1; i <= n; i += 2) {
        if (i != 5) {
          std::cout << i << ' '; 
        }
      }
      std::cout << "5 4" << ' ';
      for (int i = 2; i <= n; i += 2) {
        if (i != 4) {
          std::cout << i << ' ';
        }  
      }
      std::cout << std::endl;
    }
  }
  return 0; 
}