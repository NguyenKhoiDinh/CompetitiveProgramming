#include <iostream>
#include <math.h>
#include <iomanip>
unsigned long long u, v;  

int main () {
  std::cin >> u >> v;
  unsigned long long S = u * u + v * v;
  unsigned long long d = S / 4;
  unsigned long long r = S % 4;
  std::cout << d << '.';
  if (r == 0) {
    std::cout << "00";
  } 
  else if (r == 1) {
    std::cout << "25";
  }
  else if (r == 2) {
    std::cout << "50";
  }
  else {
    std::cout << "75";
  }
  return 0; 
}