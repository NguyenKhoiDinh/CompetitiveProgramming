#include <iostream> 
int n; 
double p[55], c[55]; 

int main () {
  std::cin >> n;
  int ans = -1; 
  double maxRatio = -1.000; 
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i]; 
  }
  for (int i = 1; i <= n; i++) {
    if (maxRatio < (c[i] / p[i])) {
      maxRatio = c[i] / p[i];
      ans = i; 
    }
  }
  std::cout << 1 << std::endl << ans;
  return 0; 
}