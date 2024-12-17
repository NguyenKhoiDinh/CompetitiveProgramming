#include <iostream>
#include <string>
#include <algorithm>
std::string s;
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s;
    std::reverse(s.begin(), s.end()); 
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == 'p') {
        s[i] = 'q'; 
      }
      else if (s[i] == 'q') {
        s[i] = 'p';
      }
    }
    std::cout << s << std::endl;
  }
  return 0; 
}