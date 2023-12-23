#include <iostream>
#include <queue> 
long long a[1000005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    a[i] = a[i - n]; 
  }
  long long ans = -1; 
  long long lo = 0, hi = 100000000000007LL; 
  while (lo <= hi) {
    long long mid = (lo + hi) / 2; 

  }
  std::cout << ans; 
  return 0; 
}