#include <iostream>
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::string s, f;
    std::cin >> n >> s >> f; 
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '0' && f[i] == '1') {
        ans1++;
      }
      else if (s[i] == '1' && f[i] == '0') {
        ans2++; 
      }
    }
    std::cout << std::max(ans1, ans2) << std::endl;
  }
  return 0; 
}