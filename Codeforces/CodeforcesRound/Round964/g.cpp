#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int lo = 2;
    int hi = 999;
    int ans = -1;
    while (lo <= hi) {
      int a = (2 * lo + hi) / 3; 
      int b = (lo + 2 * hi) / 3; 
      std::cout << "? " << a << ' ' << b << std::endl;
      fflush(stdout);
      int S;
      std::cin >> S; 
      if (a * b == S) {
        lo = b + 1; 
      }
      else if ((a + 1) * (b + 1) == S) {
        ans = a; 
        hi = a - 1; 
      }
      else {
        ans = b; 
        lo = a + 1; 
        hi = b - 1;
      }
    }
    std::cout << "! " << ans << std::endl;   
  }
  return 0; 
}