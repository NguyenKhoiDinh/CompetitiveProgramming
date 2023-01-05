#include <iostream> 
#include <algorithm>
#include <fstream>
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    bool same = true;
    for (int i = 1; i < (int) s.size(); i++) {
      if (s[i] != s[0]) {
        same = false;
        break;
      }
    } 
    if (same == true) {
      std::cout << s[0] << std::endl;
      continue;
    }
    for (int i = 0; i < (int) s.size(); i += 2) {
      if (s[i] != s[0]) {
        same = false;
        break; 
      }
    }
    for (int i = 1; i < (int) s.size(); i += 2) {
      if (s[i] != s[1]) {
        same = false;
        break; 
      }
    }
    if (same == true) {
      std::cout << s[1] << s[2] << std::endl; 
      continue; 
    }
    bool found = false;
    for (int d = 1; d <= n; d++) {
      if (n % d == 0) {
        bool check = true; 
        for (int i = 0; i < n; i++) {
          if (s[i] != s[i % d]) {
            check = false;
            break; 
          }
        }
        if (check == true) {
          std::string st = "";
          for (int i = 0; i < d; i++) {
            st += s[i];
          }  
          std::string rev_st = st;
          std::reverse(rev_st.begin(), rev_st.end());
          if (st == rev_st) {
            std::cout << st << std::endl; 
            found = true; 
            break; 
          }
        }
      }
    }
    if (found == true) {
      continue; 
    }
    int pos = (int) s.size() - 1;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
      if (s[i] == s.back()) {
        pos = i;
      }  
      else {
        break; 
      }
    }
    std::string ans = "";
    for (int i = 0; i <= pos; i++) {
      ans += s[i];
    }
    std::reverse(ans.begin(), ans.end()); 
    std::cout << ans << std::endl; 
  }
  return 0; 
}