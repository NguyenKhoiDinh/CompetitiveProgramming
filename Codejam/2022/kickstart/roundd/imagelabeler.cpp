#include <iostream> 
#include <algorithm> 
#include <iomanip> 
int numTest; 
int n, m; 
double a[10005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::sort(a + 1, a + n + 1); 
    int p = n - m + 2; 
    double ans = 0.0; 
    for (int i = p; i <= n; i++) {
      ans += a[i]; 
    }
    double sum = 0.0; 
    if (p % 2 == 0) {
      ans += a[p / 2]; 
    }
    else {
      ans += (a[p / 2] + a[p / 2 + 1]) / 2.0; 
    }
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl; 
  }
  return 0; 
}