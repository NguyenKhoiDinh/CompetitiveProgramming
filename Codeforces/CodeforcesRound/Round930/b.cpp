#include <iostream>
#include <math.h> 
#include <string> 
int numTest; 
std::string s[2];
int n;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n;
    for (int i = 0; i < 2; i++) {
      std::cin >> s[i]; 
    }
    std::string ans = s[0][0] + s[1]; 
    int numb = 1;          
    for (int i = 1; i < n; i++) {
      if (ans[i] == s[0][i]) {
        numb++; 
      }
      else if (ans[i] == '1' && s[0][i] == '0') {
        ans[i] = '0'; 
        numb = 1;
      }
      else if (ans[i] == '0' && s[0][i] == '1') {
        break;
      }
    }
    std::cout << ans << std::endl << numb << std::endl;
  }
  return 0; 
}         

     



 