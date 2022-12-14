#include <iostream>
int numTest;
int a[50005]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int i;  
    for (i = 1; i < n; i++) {
      if (a[i] <= a[i + 1]) {
        break;   
      }  
    }
    if (i == n) {
      std::cout << "NO" << std::endl; 
    }
    else {
      std::cout << "YES" << std::endl; 
    }
  }
  return 0; 
}