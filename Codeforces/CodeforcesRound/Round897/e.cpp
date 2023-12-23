#include <iostream>
int numTest; 
int n, k; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    int ans = 0; 
    int i; 
    for (i = 1; i <= n - k + 1; i += k) {
      std::cout << "? " << i << std::endl; 
      fflush(stdout); 
      int value;
      std::cin >> value;
      ans ^= value;  
    }
    if (n % k > 0) {
      int r = n % k; 
      i = n - k + 1 - r / 2; 
      std::cout << "? " << i << std::endl;
      fflush(stdout); 
      int value;
      std::cin >> value;
      ans ^= value;
      i = n - k + 1;
      std::cout << "? " << i << std::endl;
      fflush(stdout); 
      std::cin >> value;
      ans ^= value;
    }
    std::cout << "! " << ans << std::endl;
    fflush(stdout);
  }
  return 0; 
}