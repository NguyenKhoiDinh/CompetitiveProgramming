#include <iostream>
#include <string> 
#include <algorithm> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s;
    int n;
    std::cin >> n; 
    std::cin >> s;
    std::string ans = "";
    int i = n - 1; 
    while (i >= 0) {
      if (s[i] == '0') {
        int value = (s[i - 2] - '0') * 10 + (s[i - 1] - '0'); 
        ans += (char) (value - 1 + 'a'); 
        i = i - 3; 
      }
      else {
        ans += (char) (s[i] - '0' - 1 + 'a'); 
        i--; 
      }
    }
    std::reverse(ans.begin(), ans.end()); 
    std::cout << ans << std::endl;
  }
  return 0; 
}

