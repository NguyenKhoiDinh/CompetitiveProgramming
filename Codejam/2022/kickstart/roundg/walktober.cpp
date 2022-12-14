#include <iostream> 
#include <math.h> 
int numTest; 
int a[1005][33]; 
int n, m, id; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> m >> id; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cin >> a[i][j]; 
      }    
    }
    int ans = 0; 
    for (int j = 1; j <= m; j++) {
      int maxValue = -1; 
      for (int i = 1; i <= n; i++) {
        if (i != id) {
          maxValue = std::max(maxValue, a[i][j]);   
        }
      }
      ans += std::max(0, maxValue - a[id][j]);
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}