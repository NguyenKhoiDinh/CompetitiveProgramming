#include <iostream> 
#include <math.h>
double a[200005]; 
int n, k; 

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  double lo = 0.000000001; 
  double hi = 1000000000.0000; 
  for (int step = 1; step <= 50; step++) {
    double mid = (lo + hi) / 2; 
    long long total = 0LL; 
    for (int i = 1; i <= n; i++) {
      total += (long long) (a[i] / mid); 
      if (total > k) {
        break; 
      }
    }
    if (total > k) {
      lo = mid;
    }
    else {
      hi = mid; 
    }
  }
  std::cout << (int) std::ceil(lo); 
  return 0; 
}