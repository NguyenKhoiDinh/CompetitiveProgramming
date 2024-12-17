#include <iostream> 
#include <string> 
#include <math.h>
int numTest; 
std::string s; 
int change(int x, int y) {
  return std::abs(x - y); 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s; 
    int n = (int) s.size(); 
    int l = 0;
    int r = n - 1; 
    int ans = 0; 
    while (l < r) {
      int numbChange = 100; 
      for (int d = 0; d <= 9; d++) {
        numbChange = std::min(numbChange, change(s[l] - '0', d) + change(s[r] - '0', d));   
      }
      ans += numbChange; 
      l++;
      r--; 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}