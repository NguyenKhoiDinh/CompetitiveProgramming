#include <iostream> 
#include <string> 
#include <algorithm>
int numTest; 
std::string A, B; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> A >> B;
    A = "0" + A; 
    B = "0" + B; 
    std::string x = "0", y = "0"; 
    for (int i = 1; i < (int) A.size(); i++) {
      char c1 = A[i], c2 = B[i];
      if (c1 < c2) {
        std::swap(c1, c2); 
      }
      if (x >= y) {
        x += c2;
        y += c1;   
      }
      else {
        x += c1;
        y += c2; 
      }
    }
    for (int i = 1; i < (int) x.size(); i++) {
      std::cout << x[i];
    }
    std::cout << std::endl;
    for (int i = 1; i < (int) y.size(); i++) {
      std::cout << y[i];
    }
    std::cout << std::endl;
  }
  return 0; 
}