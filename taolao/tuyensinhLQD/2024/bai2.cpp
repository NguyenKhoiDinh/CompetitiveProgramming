#include <iostream>
#include <string> 

int main () {
  freopen("bai2.inp", "r", stdin);
  freopen("bai2.out", "w", stdout);
  int n;
  std::string s; 
  std::cin >> n >> s; 
  int ans = 0; 
  std::string s1 = s; 
  for (int i = 0; i < n; i++) {
    if (s1[i] == '*') {
      s1[i] = 'A'; 
    }
  }
  int numbA = 0, numbB = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s1[i] == 'A' && s1[i + 1] == 'A') {
      numbA++; 
    }
    if (s1[i] == 'B' && s1[i + 1] == 'B') {
      numbB++; 
    }
  }
  ans = std::max(ans, std::max(numbA, numbB)); 
  numbA = 0;
  numbB = 0; 
  std::string s2 = s; 
  for (int i = 0; i < n; i++) {
    if (s2[i] == '*') {
      s2[i] = 'B'; 
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (s2[i] == 'A' && s2[i + 1] == 'A') {
      numbA++; 
    }
    if (s2[i] == 'B' && s2[i + 1] == 'B') {
      numbB++; 
    }
  }
  ans = std::max(ans, std::max(numbA, numbB)); 
  std::cout << ans;
  return 0; 
}