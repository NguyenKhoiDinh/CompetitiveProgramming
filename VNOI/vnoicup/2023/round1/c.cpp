#include <iostream> 
#include <algorithm>
#include <math.h>
int a[100005];
int b[100005]; 
int n, numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i];
    }
    std::sort(a + 1, a + n + 1); 
    std::sort(b + 1, b + n + 1); 
    std::reverse(b + 1, b + n + 1); 
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      ans += std::max(a[i], b[i]); 
    }
    std::cout << ans << std::endl; 
  }
  return 0;   
}