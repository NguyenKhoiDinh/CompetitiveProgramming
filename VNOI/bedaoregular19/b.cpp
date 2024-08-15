#include <iostream>
#include <math.h>
int cnt[30]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x; 
    for (int b = 0; b < 30; b++) {
      if (((x >> b) & 1) > 0) {
        cnt[b]++; 
      }
    }
  }
  int ans = cnt[0]; 
  for (int i = 0; i < 30; i++) {
    ans = std::max(ans, cnt[i]); 
  }
  std::cout << ans;
  return 0; 
}