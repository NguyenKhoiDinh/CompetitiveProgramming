#include <iostream> 
#include <vector>
#include <math.h>
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
    if (a[1] != a[n]) {
      std::cout << 0 << std::endl;
      continue; 
    }
    int l = -1, r = -1; 
    for (int i = 1; i < n; i++) {
      if (a[i] != a[n]) {
        l = i;
        break; 
      }
    }
    for (int i = n; i > 1; i--) {
      if (a[i] != a[1]) {
        r = i;
        break;
      }
    }
    if (l == -1 || r == -1) {
      std::cout << -1 << std::endl;
      continue;
    }
    int ans = std::min(n - (n - l + 1), n - r); 
    std::vector <int> p; 
    for (int i = 2; i <= n; i++) {
      if (a[i] != a[1]) {
        p.push_back(i);          
      }
    }
    if ((int) p.size() > 1) {
      for (int i = 0; i < (int) p.size() - 1; i++) {
        ans = std::min(ans, p[i + 1] - p[i] - 1); 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}