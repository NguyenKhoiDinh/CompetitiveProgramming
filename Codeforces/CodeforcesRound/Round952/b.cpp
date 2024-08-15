#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    int ans = -1; 
    int maxSum = -1;
    for (int x = 2; x <= n; x++) {
      int sum = 0;
      for (int y = x; y <= n; y += x) {
        sum += y; 
      }
      if (maxSum < sum) {
        maxSum = sum;
        ans = x;
      }
    }  
    std::cout << ans << std::endl;
  }
  return 0; 
}