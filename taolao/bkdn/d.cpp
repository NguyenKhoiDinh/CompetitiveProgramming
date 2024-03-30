#include <iostream>
#include <math.h> 
int n, m; 
int f[205][105]; 
struct shirt {
  int A, B, X; 
};
int temp[205]; 
shirt a[105]; 

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> temp[i]; 
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i].A >> a[i].B >> a[i].X; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = -1; 
    }
  }
  for (int j = 1; j <= m; j++) {
    if (a[j].A <= temp[1] && temp[1] <= a[j].B) {
      f[1][j] = 0; 
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (f[i][j] == -1) {
        continue; 
      }
      for (int k = 1; k <= m; k++) {
        if (a[k].A <= temp[i + 1] && temp[i + 1] <= a[k].B) {
          f[i + 1][k] = std::max(f[i + 1][k], f[i][j] + std::abs(a[j].X - a[k].X)); 
        }
      }
    }
  }
  int ans = -1; 
  for (int j = 1; j <= m; j++) {
    ans = std::max(ans, f[n][j]); 
  }
  std::cout << ans; 
  return 0; 
}