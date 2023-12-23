#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int mex = 0; 
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x; 
      if (x == mex) {
        mex++; 
      }
    }
    int x = mex; 
    while (true) {
      std::cout << x << std::endl;
      fflush(stdout);
      int y;
      std::cin >> y;
      if (y == -1) {
        break; 
      } 
      else {
        x = y; 
      }
    }
  }
  return 0; 
}