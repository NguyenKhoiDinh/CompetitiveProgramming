#include <iostream>
int numTest; 
int b, c, h; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> b >> c >> h; 
    int ans = 0; 
    int numb = c + h; 
    while (b > 0) {
      b--; 
      ans++; 
      if (b == 0 || numb == 0) {
        break; 
      }
      numb--;
      ans++; 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}