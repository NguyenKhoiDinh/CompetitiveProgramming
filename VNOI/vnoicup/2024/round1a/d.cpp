#include <iostream>
#include <iomanip>
#include <queue> 
#include <math.h>
int numTest; 
double x[200005];
struct element {
  double len; 
  int left, mid, right; 
  bool operator < (const element &other) const {
    return (len < other.len || (len == other.len && len - 2.0 * std::min(x[mid] - x[left], x[right] - x[mid]) >= other.len - 2.0 * std::min(x[other.mid] - x[other.left], x[other.right] - x[other.mid]))); 
  }
}; 
int n;
int nextLeft[200005], nextRight[200005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    double midPoint = 0.0;
    for (int i = 1; i <= n; i++) {
      std::cin >> x[i]; 
      midPoint += x[i]; 
    }
    midPoint /= (double) n;
    double ans = 0.0;  
    for (int i = 1; i <= n; i++) {
      if (x[i] <= midPoint) {
        ans -= x[i];
      }
      else {
        ans += x[i];
      }
    }
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  }
  return 0; 
}