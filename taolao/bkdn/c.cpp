#include <iostream>
#include <string> 
#include <vector>

int main () {
  std::string s; 
  int ans = 0;
  int n;
  std::cin >> n;
  std::cin >> s;
  for (int i = 1; i <= n; i++) {
    std::string st;
    std::cin >> st; 
    for (int j = 0; j < (int) st.size(); j++) {
      if (st[j] == s[0]) {
        int p = 0; 
        int q = j;
        bool found = false;  
        for (int d = 1; d <= (int) st.size() - j; d++) {
          bool check = true; 
          while (q < (int) st.size()) {
            q += d;
            p++;
            if (p == (int) s.size()) {
              break; 
            }
            if (s[p] != st[q]) {
              check = false; 
              break; 
            }
          }
          if (p < (int) s.size()) {
            check = false; 
          }
          if (check == true) {
            found = true;
            break;
          }
        }
        if (found == true) {
          ans++; 
        }
      }
    }
  }
  std::cout << ans;
  return 0; 
}