#include <iostream>
#include <math.h> 
#include <iomanip> 
#include <random> 
const double PI = std::acos(-1);
struct spaceShip {
  double T, s, a; 
}; 
spaceShip v[100005]; 
int n;
double ans = 0.0; 
double solve(const double &angle) {
  double sum = 0.0; 
  for (int i = 1; i <= n; i++) {
    sum += std::max(0.0, v[i].T - v[i].s * std::min(std::fabs(angle - v[i].a), 2.0 * PI - std::fabs(angle - v[i].a)));   
  }                               
  ans = std::max(ans, sum);  
  return sum; 
} 

int main () {
  std::default_random_engine engine;
  std::uniform_int_distribution <long long> dist(0, 360LL);  
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i].T >> v[i].s >> v[i].a; 
  } 
  ans = 0.0;
  const double eps = 0.0000001;   
  double delta = 2.0 * PI / 500.0; 
  for (int step = 1; step <= 500; step++) {
    double l = 1.0 * (step - 1) * delta;
    double r = 1.0 * step * delta;              
    double angle = l + 1.0 * (1.0 * dist(engine) / 360) * delta;
    solve(angle);
  }  
  std::cout << std::fixed << std::setprecision(7) << ans; 
  return 0; 
}