#include <iostream>
int numTest; 
int a[200005];
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }  
    int i = n;
    int start = i;
    int ans = 0; 
    int len = 0; 
    while (i >= 1) {
      if (a[i] == a[n]) {
        len++;
        i--; 
      }
      else {
        ans++; 
        i = i - len;
        len *= 2;
      }    
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}