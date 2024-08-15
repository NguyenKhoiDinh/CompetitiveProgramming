#include <iostream>
#include <math.h>
long long a[2000005], b[2000005]; 

int main () {
  int n, t;
  std::cin >> n >> t; 
  long long maxValue = 0LL; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    maxValue = std::max(maxValue, a[i]);
    b[i] = maxValue;
    a[i] += a[i - 1];  
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > t) {
      std::cout << 1 << std::endl; 
    }
    else {
      std::cout << (t - a[i]) / b[i] + 2 << std::endl; 
    }
  }
  return 0;   
}