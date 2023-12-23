#include <iostream>
#include <string>
int numTest; 
int n;
std::string s; 
int ans[100005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cin >> s; 
    int l = 0, r = n - 1; 
    int numb = 0; 
    int lim = 0; 
    while (l < r) {
      if (s[l] != s[r]) {
        numb++; 
        lim++; 
      }
      else {
        lim += 2; 
      }
      l++;
      r--;   
    }
    for (int i = 0; i <= n; i++) {
      ans[i] = 0; 
    }
    for (int i = numb; i <= lim; i += 2) {
      ans[i] = 1; 
    }    
    if (n % 2 == 1) {
      lim++;
      for (int i = numb + 1; i <= lim; i += 2) {
        ans[i] = 1;
      }
    }
    for (int i = 0; i <= n; i++) {
      std::cout << ans[i];
    }
    std::cout << std::endl;
  }
  return 0; 
}