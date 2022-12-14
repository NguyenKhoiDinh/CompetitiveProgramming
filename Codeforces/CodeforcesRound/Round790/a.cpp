#include <iostream> 
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s;
    std::cin >> s; 
    std::cout << (s[0] + s[1] + s[2] == s[3] + s[4] + s[5] ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}