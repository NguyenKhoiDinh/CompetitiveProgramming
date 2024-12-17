#include <iostream>
#include <math.h>
int numTest;
int n, a, b, c; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> a >> b >> c; 
    a = std::min(a, n);
    b = std::min(b, n);
    int ans = a + b;
    ans += std::min(c, n - a + n - b);
    std::cout << ans << std::endl;   
  }
  return 0; 
}