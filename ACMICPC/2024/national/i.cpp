#include <iostream>
#include <string> 
int n, numTest; 
std::string a, b; 
std::string convert(std::string s) {
  while (true) {
    int pos = -1; 
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        if (s[i] == '1' || (s[i] == '0' && i > 0 && s[i - 1] == '1')) {
          pos = i; 
          break; 
        }
      }
    }
    if (pos == -1) {
      break; 
    }
    if (s[pos] == '0') {
      s[pos]++; 
    }           
    else {
      s[pos]--; 
    }
    if (s[pos + 1] == '0') {
      s[pos + 1]++; 
    }
    else {
      s[pos + 1]--; 
    }
  }
  return s; 
}
int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    std::cin >> a >> b;
    a = convert(a);
    b = convert(b); 
    std::cout << (a == b ? "YES" : "NO") << std::endl;
  } 
  return 0; 
}                                 




