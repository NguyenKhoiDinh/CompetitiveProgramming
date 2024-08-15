#include <iostream>
#include <algorithm> 
double a[5005]; 
int n;
double x; 

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::sort(a + 1, a + n + 1);  
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (x >= a[i]) {
        ans++; 
      }  
      else {
        break; 
      }
      x *= 1.0 * (i + 1) / (double) i; 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}