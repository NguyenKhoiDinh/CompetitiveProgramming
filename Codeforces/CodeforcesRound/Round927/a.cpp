#include <iostream>
#include <string> 
#include <math.h>
int numTest; 
int f[55]; 
int n;
std::string s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n >> s;
    const int inf = -1;  
    for (int i = 0; i <= n; i++) {
      f[i] = inf; 
    }
    f[0] = 0; 
    for (int i = 0; i < n; i++) {
      if (f[i] == inf) {
        continue; 
      }
      if (s[i] != '*') {
        f[i + 1] = std::max(f[i + 1], f[i] + (s[i] == '@'));   
      }
      if (i + 2 <= n && s[i + 1] != '*') {
        f[i + 2] = std::max(f[i + 2], f[i] + (s[i + 1] == '@'));   
      }
    }
    int ans = -1; 
    for (int i = 0; i <= n; i++) {
      ans = std::max(ans, f[i]); 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}