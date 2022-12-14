#include <iostream> 
#include <string>
#include <math.h>  
int numTest; 
std::string s; 
int n;
char color; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> color; 
    std::cin >> s; 
    if (color == 'g') {
      std::cout << 0 << std::endl; 
      continue; 
    }
    s += s; 
    n = (int) s.size();
    int greenPosition = -1; 
    int ans = -1; 
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'g') {
        greenPosition = i; 
      }  
      else if (s[i] == color) {
        ans = std::max(ans, greenPosition - i); 
      }
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}