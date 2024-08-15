#include <iostream>
#include <string>
#include <algorithm>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s;
    std::cin >> s; 
    bool check = false; 
    for (int i = 1; i < (int) s.size(); i++) {
      if (s[i] != s[0]) {
        std::swap(s[i], s[0]); 
        std::cout << "YES" << std::endl;
        std::cout << s << std::endl;
        check = true;
        break; 
      }
    }
    if (check == false) {
      std::cout << "NO" << std::endl;
    }
  }
  return 0; 
}