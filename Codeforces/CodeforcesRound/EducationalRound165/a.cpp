#include <iostream>
int numTest; 
int p[55]; 
int n; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i];
    }
    int ans = 3; 
    for (int i = 1; i <= n; i++) {
      int nxt = p[i]; 
      if (i == p[nxt] && nxt == p[i]) {
        ans = 2; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}