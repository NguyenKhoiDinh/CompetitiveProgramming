#include <iostream> 
#include <math.h>
#include <algorithm> 
int numTest; 
int n, k;
int a[200005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }   
    if (n == 1) {
      if (k < a[1] + 1) {
        std::cout << k - 1 << std::endl;   
      }
      else {
        std::cout << k << std::endl; 
      }
      continue;
    }
    std::sort(a + 1, a + n + 1); 
    int gcd = a[1]; 
    for (int i = 2; i <= n; i++) {
      gcd = std::__gcd(gcd, a[i]); 
    }
    long long value = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = value; 
      value += gcd; 
    }
    int ans = 0; 
    for (int i = 2; i <= n; i++) {
      if (a[i] == a[i - 1]) {
        continue;
      }
      if (k > a[i] - a[i - 1] - 1) {
        k -= a[i] - a[i - 1] - 1; 
      }
      else {
        ans = a[i - 1] + k;  
        break; 
      }
    }
    std::cout << (ans == 0 ? a[n] + k : ans) << std::endl;
  }
  return 0; 
}     
