#include <iostream> 

int main () {
  int n;
  std::cin >> n; 
  int ans = n / 4096; 
  if (n % 4096 > 0) {
    ans++; 
  }
  std::cout << 4 * ans; 
  return 0;
}