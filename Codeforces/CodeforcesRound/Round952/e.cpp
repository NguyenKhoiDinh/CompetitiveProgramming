#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    long long k;
    std::cin >> k;
    long long ans = 0LL; 
    for (int i = 1; i <= x; i++) {
      if (k % i != 0) {
        continue; 
      }
      long long tmp = k / i;
      for (int j = 1; j <= y; j++) {
        if (tmp % j != 0) {
          continue; 
        }
        tmp /= j; 
        if (tmp <= z) {
          ans = std::max(ans, 1LL * (x - i + 1) * (y - j + 1) * (z - tmp + 1)); 
        }
        tmp *= j;
      }
    }  
    std::cout << ans << std::endl;
  }
  return 0; 
}