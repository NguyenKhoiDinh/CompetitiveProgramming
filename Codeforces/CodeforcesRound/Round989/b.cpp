#include <iostream>
#include <string> 
int numTest; 
int n, m, k;
std::string s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k;
    std::cin >> s; 
    int ans = 0; 
    int consect = 0; 
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        consect++; 
      }
      else {
        consect = 0; 
      }
      if (consect == m) {
        ans++;
        i += k - 1;
        consect = 0;  
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}