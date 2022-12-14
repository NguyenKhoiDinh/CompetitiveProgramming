#include <iostream>
#include <math.h>
#include <iomanip>

int main () {
  double n, x1, y1, a, b;
  std::cin >> n >> x1 >> y1 >> a >> b; 
  double ans = std::sqrt(a * a + b * b); 
  ans *= n;
  ans *= 0.5; 
  std::cout << std::fixed << std::setprecision(12) << ans;
  return 0; 
}