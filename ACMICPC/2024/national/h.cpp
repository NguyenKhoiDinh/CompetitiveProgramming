#include <iostream>
#include <algorithm> 
int numTest; 
int a[200005], b[200005]; 
int n, x; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      b[i] = a[i];
      if (b[i] == -1) {
        b[i] = x; 
      }
    }
    std::sort(b + 1, b + n + 1); 
    if (b[n / 2 + 1] == x) {
      std::cout << "YES" << std::endl;
      for (int i = 1; i <= n; i++) {
        std::cout << (a[i] == -1 ? x : a[i]) << ' ';
      }
      std::cout << std::endl; 
    }
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}