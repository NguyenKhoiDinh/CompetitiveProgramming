#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int w, b;
    std::cin >> w >> b; 
    long long lo = 0;
    long long hi = (w + b);
    long long n = -1;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2; 
      if (mid * (mid + 1) / 2 <= (w + b)) {
        n = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1;
      }
    } 
    std::cout << n << std::endl;
  }
  return 0; 
}