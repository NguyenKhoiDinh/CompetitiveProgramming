#include <iostream> 
#include <iomanip>
#include <algorithm>
struct element {
  int t;
  double p; 
  double mul; 
  bool operator < (const element &other) {
    return mul < other.mul; 
  }
}; 
int n; 
element a[500005]; 
double ans = 0.0; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].t >> a[i].p;
    a[i].mul = a[i].t * a[i].p; 
  }
  std::sort(a + 1, a + n + 1); 
  double sum = 0.0; 
  for (int i = 1; i <= n; i++) {
    sum = (sum + a[i].t) * a[i].p + sum * (1.0 - a[i].p); 
    ans += sum; 
  }
  std::cout << std::fixed << std::setprecision(12) << ans / n; 
  return 0; 
}