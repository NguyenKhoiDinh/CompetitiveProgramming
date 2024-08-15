#include <iostream>
#include <iomanip> 

int main () {
  std::cout << std::fixed << std::setprecision(12); 
  int n, m, k; 
  std::cin >> n >> m >> k; 
  if (m < k) {
    std::cout << (double) m / k; 
  }
  else {
    std::cout << (double) (k - 1 + (double) (m - k + 1) / (double) (m - k + 1 + n)) * 1.0 / k;  
  }
  return 0; 
}