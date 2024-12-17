#include <iostream> 
int numTest; 
int a[55];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    int total = 0;
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) {
        if (total > 0) {
          ans++;
          total--; 
        }
      }  
      else if (a[i] >= k) {
        total += a[i]; 
      }
    }  
    std::cout << ans << std::endl;
  }
  return 0; 
}