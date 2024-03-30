#include <iostream>

int main () {
  int n, X, Y, A, B;
  std::cin >> n >> X >> Y >> A >> B; 
  std::cout << n - std::max((X + A - 1) / A, (Y + B - 1) / B); 
  return 0; 
}