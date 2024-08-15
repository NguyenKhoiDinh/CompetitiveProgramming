#include <iostream>

int main () {
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    long long numb1 = 0, numb2 = 0; 
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      if (x == 1) {
        numb1++;  
      }
      else if (x == 2) {
        numb2++; 
      }
      else {
        numb1 += x - 2; 
        numb2++; 
      }
    }
    std::cout << numb1 / 2 + numb2 / 2 << std::endl;
  }
  return 0; 
}