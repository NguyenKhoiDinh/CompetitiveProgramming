#include <iostream>
#include <algorithm>
#include <math.h>
int a[100005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + n + 1);
  int prev_g = -1; 
  for (int i = 1; i < n; i++) {
    int g = std::__gcd(a[i], a[i + 1]);
    if (prev_g != -1 && prev_g != g) {
      int tmp = std::__gcd(prev_g, g);
      if (tmp == 1) {
        std::cout << a[i - 1] << ' ' << a[i + 1]; 
        return 0; 
      }
    } 
    prev_g = g; 
    if (g == 1) {
      std::cout << a[i] << ' ' << a[i + 1];
      return 0;
    }
  }
  std::cout << "-1 -1";
  return 0; 
}