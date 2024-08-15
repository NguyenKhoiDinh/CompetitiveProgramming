#include <iostream>
#include <math.h> 
int numTest; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; 
int a[105][105]; 
int n, m;

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cin >> a[i][j]; 
      }
    }  
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int maxi = -1;
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
            maxi = std::max(maxi, a[ni][nj]); 
          }
        } 
        if (a[i][j] > maxi) {
          a[i][j] = maxi; 
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cout << a[i][j] << ' '; 
      }
      std::cout << std::endl;
    }
  }
  return 0; 
}