#include <iostream>
#include <algorithm>

int main () {
  long long x, k;
  std::cin >> x >> k;
  long long gcd = std::__gcd(x, k); 
  std::cout << k / gcd;
  return 0; 
}