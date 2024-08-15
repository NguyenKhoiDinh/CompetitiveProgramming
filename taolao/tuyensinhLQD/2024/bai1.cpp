#include <iostream>

int main () {
  freopen("bai1.inp", "r", stdin);
  freopen("bai1.out", "w", stdout);
  int a, b;
  std::cin >> a >> b; 
  int ans = a;  
  if (b > 0) {
    ans += (b + 2) / 3; 
  }
  std::cout << ans;
  return 0; 
}