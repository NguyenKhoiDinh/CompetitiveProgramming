#include <iostream> 
#include <algorithm> 
int numTest; 
int a[55]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    int sum = 0; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      sum += a[i]; 
    }
    std::sort(a + 1, a + n + 1); 
    std::cout << sum - a[1] * n << std::endl;
  }
  return 0; 
}