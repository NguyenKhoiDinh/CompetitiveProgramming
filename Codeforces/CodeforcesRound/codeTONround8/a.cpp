#include <iostream>

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    std::cin >> n >> k; 
    if (k == 1) {
      for (int i = 1; i <= n; i++) {
        std::cout << i << ' '; 
      }
    }
    else if (k == n) {
      for (int i = 1; i <= n; i++) {
        std::cout << 1 << ' '; 
      }
    }
    else {
      std::cout << -1;
    }
    std::cout << std::endl;
  }
  return 0; 
}