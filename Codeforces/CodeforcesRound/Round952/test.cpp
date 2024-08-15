#include <iostream>
int sumDigit(int n) {
  int ret = 0;
  while (n > 0) {
    ret += n % 10;
    n /= 10; 
  }
  return ret; 
}

int main () {
  int l, r, k;
  std::cin >> l >> r >> k; 
  for (int i = l; i <= r; i++) {
    if (sumDigit(i * k) == k * sumDigit(i)) {
      std::cout << i << "    "; 
    }
  }
  return 0; 
}