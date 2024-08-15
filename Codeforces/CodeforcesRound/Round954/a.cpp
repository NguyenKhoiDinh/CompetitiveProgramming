#include <iostream>
#include <math.h> 
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = 100; 
    for (int x = -100; x <= 100; x++) {
      ans = std::min(ans, std::abs(x - a) + std::abs(x - b) + std::abs(x - c)); 
    }     
    std::cout << ans << std::endl;
  }
  return 0; 
}