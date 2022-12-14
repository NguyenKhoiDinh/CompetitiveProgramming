#include <iostream> 
int n; 
int a[1005][1005]; 
int larger1[1005][1005], larger2[1005][1005]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j]; 
    }
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1; 
      int add = a[i][j] - a[1][1]; 
      int largeri = larger1[i][j - 1]; 
      int largerj = larger2[i + 1][j]; 
      int numbInversions = 2 * largeri - 2 * largerj;  
      if (add - numbInversions > 0) {   // pi < pj
        larger1[i][j] = larger1[i][j - 1] + 1;
        larger2[i][j] = larger2[i + 1][j];  
      }
      else {
        larger2[i][j] = larger2[i + 1][j] + 1;
        larger1[i][j] = larger1[i][j - 1]; 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << n - larger2[1][i] - larger1[i][n] << ' ';
  }
  return 0; 
}