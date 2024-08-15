#include <iostream>
#include <iomanip> 
#include <math.h> 
#include <vector> 
#include <utility>
#include <algorithm> 
int n; 
std::vector <double> a, b;
std::vector <std::pair <double, double> > c;  
double f(const double &x) {
  double res = 0.000; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        double da = a[i] - a[j];
        double db = b[i] - b[j]; 
        res = std::max(res, da * std::cos(x) + db * std::sin(x)); 
      }
    }
  }
  return res; 
}  

int main () {
  std::cin >> n; 
  a.resize(n);
  b.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i]; 
  }
  for (int i = 0; i < n; i++) {
    c.push_back(std::make_pair(a[i], b[i])); 
  }
  std::sort(c.begin(), c.end()); 
  double ans = 1000000007.00000; 
  double lo = -1000000000.000, hi = 1000000000.000;
  for (int step = 1; step <= 150; step++) {
    double u = (2.0 * lo + hi) / 3.0;
    double v = (lo + 2.0 * hi) / 3.0;
    if (f(u) <= f(v)) {
      ans = std::min(ans, f(u));
      hi = v;  
    }
    else {
      ans = std::min(ans, f(v)); 
      lo = u; 
    } 
  }
  std::cout << std::fixed << std::setprecision(12) << ans; 
  return 0; 
}