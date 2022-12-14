#include <iostream>
#include <math.h> 
int numTest; 
int a[52];
int n; 
int s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> s;
    int sum = 0; 
    int maxi = -1; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      sum += a[i]; 
      maxi = std::max(maxi, a[i]); 
    }
    bool ans = false; 
    for (int x = maxi; x <= 1000; x++) {
      if (sum + s == x * (x + 1) / 2) {
        std::cout << "YES"; 
        ans = true;
        break; 
      }
    }
    if (ans == false) {
      std::cout << "NO"; 
    }
    std::cout << std::endl;
  }
  return 0; 
}