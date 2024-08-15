#include <iostream>
#include <string> 
bool check(const char &c) {
  return (c == 'a' || c == 'i' || c == 'u' || c == 'y' || c == 'o' || c == 'e'); 
}

int main () {
  std::string s, t; 
  std::cin >> s >> t; 
  for (int i = 0; i < (int) s.size(); i++) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      s[i] = s[i] - 'A' + 'a'; 
    }
  }
  for (int i = 0; i < (int) t.size(); i++) {
    if ('A' <= t[i] && t[i] <= 'Z') {
      t[i] = t[i] - 'A' + 'a'; 
    }
  }
  int n = (int) s.size();
  int m = (int) t.size(); 
  int p = 0; 
  int q = 0; 
  while (p < n && q < m) {
    if (s[p] == t[q]) {
      p++;
      q++; 
    }
    else {
      while (q < m && check(t[q]) == true && s[p] != t[q]) {
        q++; 
      }
      if (q < m && s[p] != t[q]) {
        std::cout << "Different";
        return 0; 
      }
    }
  }
  if (p < n && q == m) {
    std::cout << "Different"; 
  }
  else if (p == n) {
    while (q < m && check(t[q]) == true) {
      q++; 
    }
    std::cout << (q == m ? "Same" : "Different"); 
  }
  return 0; 
}