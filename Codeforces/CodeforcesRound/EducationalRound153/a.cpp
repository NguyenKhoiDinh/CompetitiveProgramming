#include <iostream>
#include <string> 
int numTest; 

bool check(const std::string &s, const std::string &pattern) {
  for (int i = 0; i + (int) s.size() - 1 < (int) pattern.size(); i++) {
    bool ok = true; 
    for (int j = 0; j < (int) s.size(); j++) {
      if (s[j] != pattern[i + j]) {
        ok = false;
        break; 
      }  
    }
    if (ok == true) {
      return true; 
    }
  }
  return false; 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s;
    std::cin >> s; 
    int n = (int) s.size(); 
    std::string s1 = ""; 
    for (int i = 1; i <= n; i++) {
      s1 += '(';
    }
    for (int i = 1; i <= n; i++) {
      s1 += ')';
    }
    std::string s2 = ""; 
    for (int i = 1; i <= n; i++) {
      s2 += "()"; 
    }
    if (check(s, s1) == false) {
      std::cout << "YES" << std::endl << s1 << std::endl; 
    }
    else if (check(s, s2) == false) {
      std::cout << "YES" << std::endl << s2 << std::endl;
    }
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}