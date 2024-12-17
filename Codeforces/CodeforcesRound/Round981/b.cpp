#include <iostream> 
#include <math.h> 
int a[505][505]; 
int n; 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        std::cin >> a[i][j]; 
      }
    }
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] < 0) {
          int p = i; 
          int q = j; 
          int minElement = a[i][j]; 
          while (p <= n && q <= n) { 
            minElement = std::min(minElement, a[p][q]); 
            p++;
            q++; 
          }
          p--;
          q--; 
          ans += -minElement;
          while (p >= i && q >= j) {
            a[p][q] = 0; 
            p--;
            q--; 
          } 
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}
