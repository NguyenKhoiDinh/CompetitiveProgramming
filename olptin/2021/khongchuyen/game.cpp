#include <iostream> 
#include <math.h> 
#include <algorithm>
const int inf = 1000000007;
int a[500005]; 
int n; 
int minValue[500005]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }  
  long long s = 0LL; 
  long long ans = 0LL;
  minValue[0] = inf;  
  for (int i = 1; i <= n; i++) {
    minValue[i] = std::min(minValue[i - 1], a[i]); 
  }
  for (int i = n; i >= 1; i--) {
    s += minValue[i]; 
  }
  ans = s; 
  std::reverse(a + 1, a + n + 1);
  s = 0; 
  minValue[0] = inf;  
  for (int i = 1; i <= n; i++) {
    minValue[i] = std::min(minValue[i - 1], a[i]); 
  }
  for (int i = n; i >= 1; i--) {
    s += minValue[i]; 
  } 
  ans = std::max(ans, s); 
  std::cout << ans;
  return 0;
}