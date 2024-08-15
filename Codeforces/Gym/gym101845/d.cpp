#include <iostream>
#include <math.h> 
#include <vector> 
#include <iomanip>
#include <algorithm>
struct point {
  double x, y; 
};
std::vector <point> a; 
int n, m;  
double sum[200005]; 

int main () {
  std::cin >> n >> m;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].x >> a[i].y; 
  }
  for (int i = 0; i < n; i++) {
    a.push_back(a[i]); 
  }
  a.push_back(a[0]); 
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i].x * a[i - 1].y - a[i].y * a[i - 1].x; 
  }
  double ans = 0.0; 
  double area = 0.5 * std::abs(sum[n]); 
  for (int i = 1; i <= m; i++) {
    int p, q;
    std::cin >> p >> q;
    p--;
    q--; 
    if (p > q) {
      std::swap(p, q); 
    }
    double area1 = sum[q] - sum[p]; 
    area1 += a[p].x * a[q].y - a[q].x * a[p].y;
    area1 = 0.5 * std::abs(area1);
    double area2 = area - area1; 
    ans = std::max(ans, std::min(area1, area2)); 
  }
  std::cout << std::fixed << std::setprecision(12) << ans; 
  return 0; 
}