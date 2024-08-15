#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
double a[100005]; 

int main () {
  int n; 
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::sort(a + 1, a + n + 1); 
  double ans = 0.0;
  for (int i = 2; i <= n; i++) {
    double diff = std::abs(a[i] - a[i - 1]); 
    ans += std::sqrt(1 + diff * diff); 
  } 
  std::cout << std::fixed << std::setprecision(12) << ans;
  return 0; 
}
