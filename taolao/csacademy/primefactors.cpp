#include <iostream>

int main () {
  int ans = 1; 
  std::cout << "Q 2" << std::endl;
  int x;
  std::cin >> x; 
  for (int i = 1; i <= x; i++) {
    ans *= 2; 
  }
  std::cout << "Q 3" << std::endl;
  std::cin >> x; 
  for (int i = 1; i <= x; i++) {
    ans *= 3; 
  }
  std::cout << "Q 5" << std::endl;
  std::cin >> x; 
  for (int i = 1; i <= x; i++) {
    ans *= 5; 
  }
  std::cout << "Q 7" << std::endl;
  std::cin >> x; 
  for (int i = 1; i <= x; i++) {
    ans *= 7; 
  }
  std::cout << "A " << ans << std::endl;
  return 0; 
}