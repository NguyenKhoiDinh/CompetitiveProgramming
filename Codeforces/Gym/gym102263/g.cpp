#include <iostream>
#include <iomanip> 

int main () {
  int n; 
  std::cin >> n; 
  double ans = 0.0; 
  for (int i = 1; i <= n; i++) {
    ans += 1.0 * i * (i - 1) / n; 
  }
  std::cout << std::fixed << std::setprecision(12) << ans;
  return 0; 
}