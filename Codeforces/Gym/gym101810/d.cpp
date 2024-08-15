#include <iostream>
#include <algorithm>
#include <math.h> 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n, m;
    std::cin >> n >> m; 
    long long ans = n * (m + 1) + m * (n + 1) - std::abs(n - m); 
    std::cout << ans / 4 << std::endl;
  } 
  return 0; 
}