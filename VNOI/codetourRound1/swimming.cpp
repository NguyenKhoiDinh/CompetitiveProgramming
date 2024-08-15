#include <iostream>

int main () {
  long long n, k;
  std::cin >> n >> k;
  long long tmp = (n + k - 1) / k; 
  std::cout << tmp * (tmp + 1) / 2;
  return 0; 
}