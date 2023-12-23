#include <iostream> 
#include <math.h>
int numTest; 
int n; 
int b[200005]; 
int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i < n; i++) {
      std::cin >> b[i]; 
    }
    std::cout << b[1] << ' '; 
    for (int i = 2; i < n; i++) {
      std::cout << std::min(b[i], b[i - 1]) << ' '; 
    }
    std::cout << b[n - 1] << std::endl; 
  }
  return 0;   
}