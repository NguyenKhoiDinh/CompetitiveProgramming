#include <iostream>
#include <string> 
int numTest; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s1, s2;
    std::cin >> n;
    std::cin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
      if (s1[i] == 'G') {
        s1[i] = 'B'; 
      }
    }  
    for (int i = 0; i < n; i++) {
      if (s2[i] == 'G') {
        s2[i] = 'B'; 
      }
    }
    std::cout << (s1 == s2 ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}