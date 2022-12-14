#include <iostream> 
#include <string> 
#include <algorithm>
int fact[10]; 
int n; 
std::string ans; 

int main () {
  fact[0] = 1;
  for (int i = 1; i <= 9; i++) {
    fact[i] = fact[i - 1] * i; 
  }
  std::cin >> n; 
  if (n == 1) {
    std::cout << 0;
    return 0;
  }
  while (n > 0) {
    for (int x = 9; x >= 1; x--) {
      if (n >= fact[x]) {
        ans += (char) (x + '0'); 
        n -= fact[x];
        break; 
      }
    }
  }
  std::reverse(ans.begin(), ans.end());
  std::cout << ans; 
  return 0; 
}