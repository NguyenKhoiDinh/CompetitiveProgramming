#include <iostream>
#include <string> 
int numTest; 
std::string st = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes"; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s; 
    std::cin >> s;
    bool ans = false;  
    for (int i = 0; i < (int) st.size() - (int) s.size(); i++) {
      bool check = true; 
      for (int j = 0; j < (int) s.size(); j++) {
        if (st[i + j] != s[j]) {
          check = false;
          break; 
        }
      }
      if (check == true) {
        ans = true;
        break;  
      }
    }
    std::cout << (ans == true ? "YES" : "NO") << std::endl;
  }
  return 0; 
}