#include <iostream>
#include <string> 
int n, x; 

int main () {
  std::string s1, s2; 
  std::cin >> n >> x;
  x %= n;  
  std::cin >> s1 >> s2; 
  std::string prefix = "", suffix = ""; 
  for (int i = 0; i < n - x; i++) {
    prefix += s1[i]; 
  }
  for (int i = n - x; i < n; i++) {
    suffix += s1[i]; 
  }
  s1 = suffix + prefix; 
  int ans = 0; 
  for (int i = 0; i < n; i++) {
    ans += s1[i] != s2[i]; 
  }
  std::cout << ans; 
  return 0; 
}