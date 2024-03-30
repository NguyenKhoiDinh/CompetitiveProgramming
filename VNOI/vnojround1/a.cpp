#include <iostream>
#include <math.h> 
int a[5005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }                     
  int ans = -1;
  int maxValue = 0; 
  for (int j = n; j >= 2; j--) {
    for (int i = 1; i < j; i++) {
      if (a[i] < a[j] && a[j] < maxValue) {
        ans = std::max(ans, a[i] + a[j] + maxValue);    
      }
    }
    maxValue = std::max(maxValue, a[j]);
  }
  std::cout << ans;
  return 0; 
}