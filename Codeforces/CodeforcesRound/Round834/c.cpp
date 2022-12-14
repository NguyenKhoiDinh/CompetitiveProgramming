#include <iostream>
#include <math.h> 
int numTest; 
int l, r, x, a, b;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> l >> r >> x >> a >> b;
    if (a == b) {
      std::cout << 0 << std::endl;
      continue;
    }
    if (std::abs(a - l) < x && std::abs(a - r) < x) {
      std::cout << -1 << std::endl;
      continue; 
    }
    if (std::abs(b - l) < x && std::abs(b - r) < x) {
      std::cout << -1 << std::endl;
      continue; 
    }
    if (std::abs(b - a) >= x) {
      std::cout << 1 << std::endl; 
    }
    else if (std::abs(a - l) >= x && std::abs(b - l) >= x) {
      std::cout << 2 << std::endl; 
    }
    else if (std::abs(a - r) >= x && std::abs(b - r) >= x) {
      std::cout << 2 << std::endl; 
    }
    else {
      std::cout << 3 << std::endl;
    }
  }
  return 0; 
}