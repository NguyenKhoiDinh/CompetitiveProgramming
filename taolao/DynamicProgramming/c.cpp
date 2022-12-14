#include <iostream>
#include <math.h> 
int numTest; 
int n; 
int ans[100005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    int i = n - 1; 
    for (int d = (int) std::sqrt(n) + 1; d >= 0; d--) {
      if (d * d - i <= i) {
        int r = i; 
        for (int x = d * d - i; x <= i; x++) {
          ans[x] = r;
          r--;   
        }
        i = d * d - i - 1; 
      }    
    }
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << ' '; 
    }  
    std::cout << std::endl;
  }
  return 0; 
}