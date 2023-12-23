#include <iostream> 
#include <iomanip>
#include <math.h>  
int n; 
double a[100005]; 
double v[100005]; 
double X1, Y1, X2, Y2; 

double f(double x) {
  double d1 = (a[1] - X1); 
  double h1 = std::abs(x - Y1); 
  double l1 = std::sqrt(d1 * d1 + h1 * h1); 
  double d2 = (X2 - a[1]); 
  double h2 = std::abs(x - Y2); 
  double l2 = std::sqrt(d2 * d2 + h2 * h2); 
  return l1 / v[1] + l2 / v[2];
}

double getMax(double a, double b) {
  if (a > b) {
    return a;
  }
  return b; 
}

double getMin(double a, double b) {
  if (a > b) {
    return b;
  }
  return a; 
}

int main () {
  std::cin >> n; 
  for (int i = 0; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i]; 
  }
  std::cin >> X1 >> Y1 >> X2 >> Y2; 
  double lo = getMin(Y1, Y2);
  double hi = getMax(Y1, Y2); 
  for (int step = 1; step <= 100; step++) {
    double u = (2.0 * lo + hi) / 3.0;
    double v = (lo + 2.0 * hi) / 3.0; 
    if (f(u) > f(v)) {
      lo = u; 
    }
    else {
      hi = v; 
    }
  }
  std::cout << std::fixed << std::setprecision(12) << f(lo); 
  return 0; 
}