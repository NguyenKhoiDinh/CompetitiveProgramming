#include <iostream> 
#include <math.h> 
const long long inf = 10000000000000007LL;
int a[1000005];
int b[1000005];
int n, p;
long long f_max[1000005][2], f_min[1000005][2];  

int main () {
  std::cin >> n >> p; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];   
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i]; 
  }
  for (int i = 0; i <= n + 1; i++) {
    f_max[i][0] = f_max[i][1] = -inf;
    f_min[i][0] = f_min[i][1] = inf; 
  }
  f_max[0][0] = 0; 
  f_max[0][1] = 0; 
  for (int i = 0; i <= n; i++) {
    for (int state = 0; state <= 1; state++) {
      if (f_max[i][state] == -inf) {
        continue; 
      }
      for (int j = 1; j <= std::min(p, n + 1 - j); j++) {
        f_max[i + j][1 - state] = std::max(f_max[i + j][1 - state], f_max[i][state] + (state == 0 ? b[i + j] : a[i + j])); 
      }
    }
  }
  f_min[0][0] = 0; 
  f_min[0][1] = 0; 
  for (int i = 0; i <= n; i++) {
    for (int state = 0; state <= 1; state++) {
      if (f_min[i][state] == inf) {
        continue; 
      }
      for (int j = 1; j <= std::min(p, n + 1 - j); j++) {
        f_min[i + j][1 - state] = std::min(f_min[i + j][1 - state], f_min[i][state] + (state == 0 ? b[i + j] : a[i + j])); 
      }
    }
  }
  std::cout << std::max(std::max(std::abs(f_max[n + 1][0]), std::abs(f_max[n + 1][1])), std::max(std::abs(f_min[n + 1][0]), std::abs(f_min[n + 1][1])));
  return 0; 
}