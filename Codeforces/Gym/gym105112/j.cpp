#include <iostream> 
#include <math.h> 
#include <utility>
#include <vector> 
#include <iomanip>
double f[(1 << 12) + 5][12]; 
int n; 
std::vector <std::pair <double, double> > a; 
const double inf = 1000000007.0000; 

int main () {
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first >> a[i].second; 
  }
  double ans = inf; 
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (x != y) {
        std::vector <std::pair <double, double> > v; 
        double alpha = a[x].second == a[y].second ? 0.0 : std::atan((a[x].first - a[y].first) / (a[x].second - a[y].second));
        for (int i = 0; i < n; i++) {
          v.push_back(std::make_pair(a[i].first * std::cos(alpha) - a[i].second * std::sin(alpha), a[i].first * std::sin(alpha) + a[i].second * std::cos(alpha))); 
        }
        for (int mask = 0; mask < (1 << n); mask++) {
          for (int i = 0; i < n; i++) {
            f[mask][i] = inf; 
          }
        }
        for (int i = 0; i < n; i++) {
          f[1 << i][i] = 0.0; 
        }
        for (int mask = 0; mask < (1 << n); mask++) {
          for (int i = 0; i < n; i++) {
            if (f[mask][i] != inf) {
              for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0) {
                  f[mask | (1 << j)][j] = std::min(f[mask | (1 << j)][j], f[mask][i] + std::abs(v[j].first - v[i].first) + std::abs(v[j].second - v[i].second)); 
                }
              }
            }
          }
        }
        for (int i = 0; i < n; i++) {
          ans = std::min(ans, f[(1 << n) - 1][i]); 
        }
      }  
    }
  }
  std::cout << std::fixed << std::setprecision(12) << ans; 
  return 0; 
}