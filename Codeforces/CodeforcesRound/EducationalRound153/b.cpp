#include <iostream>
#include <math.h>
int numTest;
long long m, k, a1, ak;  

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> m >> k >> a1 >> ak; 
    long long t = std::max(0LL, std::min(m / k, (m - a1 + k - 1) / k));
    std::cout << std::max(0LL, t - ak) + std::max(0LL, m - t * k - a1) << std::endl;  
  }
  return 0; 
}