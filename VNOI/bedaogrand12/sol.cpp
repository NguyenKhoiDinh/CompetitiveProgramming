#include <iostream> 
#include <algorithm> 
int n; 
int cntOdd = 0, cntEven = 0; 
int a[1000005];                       

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0; 
  for (int i = 1; i < n; i++) {
    if (i % 2 != a[i] % 2 && ((i + 1) % 2 != a[i + 1] % 2)) {
      ans++;
      std::swap(a[i], a[i + 1]); 
      i++; 
    }
  } 
  for (int i = 1; i <= n; i++) {
    if (i % 2 != a[i] % 2) {
      std::cout << -1;
      return 0;
    }
  }
  std::cout << ans;
  return 0; 
}