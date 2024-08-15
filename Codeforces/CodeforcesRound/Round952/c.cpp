#include <iostream>
#include <math.h>
int numTest; 
int n;
int a[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    long long sum = 0LL; 
    int maxi = -1; 
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      maxi = std::max(maxi, a[i]); 
      sum += a[i]; 
      if (maxi == sum - maxi) {
        ans++;
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}