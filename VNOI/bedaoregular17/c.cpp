#include <iostream>
#include <math.h> 
int f[100005]; 
int a[105]; 
int k, n; 

int main () {
  std::cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  f[0] = 0; 
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= a[j]) {
        f[i] = std::max(f[i], i - f[i - a[j]]);
      }
    }
  }
  std::cout << f[k];
  return 0;
}