#include <iostream> 

int main () {
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n; 
    int mex = 0;
    for (int i = 1; i <= n; i++) {
      int p;
      std::cin >> p; 
      if (p > 0) {
        std::cout << mex << ' '; 
        mex += p; 
      }
      else {
        std::cout << mex - p << ' ';
      }
    }
    std::cout << std::endl;
  }
  return 0; 
}