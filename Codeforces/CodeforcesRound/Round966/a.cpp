#include <iostream> 
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {  
    std::string s; 
    std::cin >> s; 
    if (s == "101") {
      std::cout << "NO";
      std::cout << std::endl;
      continue;
    }
    if ((int) s.size() <= 2) {
      std::cout << "NO"; 
    }
    else {
      if (s[0] == '1' && s[1] == '0' && s[2] != '0') {
        std::cout << "YES"; 
      }
      else {
        std::cout << "NO";
      }
    }
    std::cout << std::endl;
  }
  return 0; 
}