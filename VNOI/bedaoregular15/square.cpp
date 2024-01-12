#include <iostream> 

int main () { 
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cout << i * i * i << ' ';
  }
  return 0; 
}