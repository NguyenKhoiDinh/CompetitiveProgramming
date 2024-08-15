#include <iostream>
int h[2005]; 
int n; 

int main () {
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      std::cin >> h[i]; 
    }
    int l = 1;
    int r = 2 * n;
    int ans = 0; 
    while (l <= r) {
      ans = std::max(ans, h[l] + h[r]);
      l++;
      r--;  
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}