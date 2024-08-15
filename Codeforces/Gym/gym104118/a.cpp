#include <iostream>

int main () {
  int x;
  std::cin >> x; 
  int a = -2; 
  int b = 1;
  int c = -14; 
  int d = 17; 
  if (x <= -3) {
    std::cout << -(x + 4) * (x + 4) + 8; 
  }
  else if (x <= 2) {
    std::cout << a * x + b; 
  }
  else {
    std::cout << x * x * x + c * x + d; 
  }
  return 0; 
}