#include <iostream>
int numTest; 
int a[200005], c[200005]; 
int h, n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> h >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> c[i]; 
    }
    long long lo = 1; 
    long long hi = 40000000007LL;
    long long ans = 0; 
    while (lo <= hi) {
      long long mid = (lo + hi) / 2; 
      long long totalDam = 0LL; 
      for (int i = 1; i <= n; i++) {
        totalDam += (long long) ((mid - 1) / c[i] + 1) * a[i]; 
      }
      if (totalDam >= h) {
        ans = mid; 
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}