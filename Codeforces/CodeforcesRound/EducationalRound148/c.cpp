#include <iostream> 
int numTest; 
int a[300005]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int dir = 0; 
    int ans = 1; 
    for (int i = 2; i <= n; i++) {
      if (a[i] == a[i - 1]) {
        continue; 
      }
      if (a[i] > a[i - 1] && dir == 1) {
        continue; 
      }
      if (a[i] < a[i - 1] && dir == 2) {
        continue; 
      }
      ans++; 
      if (a[i] > a[i - 1]) {
        dir = 1;
      }
      else {
        dir = 2; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}