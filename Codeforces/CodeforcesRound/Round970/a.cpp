#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b;
    std::cin >> a >> b;
    if (a % 2 == 1) {
      std::cout << "NO" << std::endl;
      continue; 
    }  
    bool found = false; 
    while (a > 0 && b > 0) {
      if (b % 2 == 0) {
        found = true;   
      }
      a -= 2;
      b--; 
    }
    if (found == true || (a % 2 == 0 && b % 2 == 0)) {
      std::cout << "YES"; 
    }
    else {
      std::cout << "NO"; 
    }
    std::cout << std::endl;
  }
  return 0; 
}