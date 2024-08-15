#include <iostream> 
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s, t; 
    std::cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size(); 
    int pt = 0; 
    int ps = 0; 
    while (pt < m) {
      while (ps < n && s[ps] != '?' && s[ps] != t[pt]) {
        ps++; 
      }
      if (ps == n) {
        break; 
      }
      else {
        if (s[ps] == '?') {
          s[ps] = t[pt]; 
        }
        pt++;
        ps++; 
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        s[i] = 'a'; 
      }
    }
    if (pt == m) {
      std::cout << "YES" << std::endl; 
      std::cout << s << std::endl; 
    }
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}