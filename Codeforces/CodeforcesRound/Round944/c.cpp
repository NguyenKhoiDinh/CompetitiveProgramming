#include <iostream>
#include <algorithm>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a > b) {
      std::swap(a, b);
    }
    bool isC = false, isD = false;
    for (int i = a; i <= b; i++) {
      if (i == c) {
        isC = true; 
      }
      if (i == d) {
        isD = true; 
      }
    }
    if (isC == isD) {
      std::cout << "NO";
    }  
    else {
      std::cout << "YES";
    }
    std::cout << std::endl;
  }
  return 0; 
}