#include <iostream>
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::string s; 
    std::cin >> s; 
    int A = 0;
    int B = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == 'A') {
        A++; 
      }
      else {
        B++;
      }
    }
    std::cout << (A > B ? 'A' : 'B') << std::endl;
  }
  return 0; 
}