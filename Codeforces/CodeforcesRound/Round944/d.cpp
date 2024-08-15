#include <iostream>
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s; 
    std::cin >> s;
    bool check = false; 
    int ans = 1; 
    for (int i = 1; i < (int) s.size(); i++) {
      if (s[i] != s[i - 1]) {
        if (s[i] == '1' && s[i - 1] == '0' && check == false) {
          check = true;
          continue; 
        }
        ans++; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}