#include <iostream>
#include <math.h>
 
bool ok[1000005]; 
int a[1000005];
int n; 
int ans = 0; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    if (ok[a[i] + 1] == true) {
      ans++; 
    }
    ok[a[i]] = true; 
  } 
  if (ans == 0) {
    std::cout << 0;
    return 0; 
  }
  std::cout << 1 + (int) (std::log2(ans));
  return 0; 
}
