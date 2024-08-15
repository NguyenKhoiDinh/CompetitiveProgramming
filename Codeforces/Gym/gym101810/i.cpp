#include <iostream>
#include <vector> 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, n;
    std::cin >> x >> n;
    if (x < n) {
      std::cout << -1 << std::endl; 
    }
    else {
      std::vector <int> ans(n);
      for (int i = 0; i < n; i++) {
        ans[i] = x / n; 
      }  
      int r = x % n; 
      int p = n - 1; 
      while (r > 0) {
        ans[p]++; 
        p--;
        r--; 
      }
      for (int i = 0; i < n; i++) {
        std::cout << ans[i] << ' ';
      }
      std::cout << std::endl;
    }
  }
  return 0; 
}