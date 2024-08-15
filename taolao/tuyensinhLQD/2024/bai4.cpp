#include <iostream>
long long prefix[1000005]; 

int main () {
  freopen("bai4.inp", "r", stdin);
  freopen("bai4.out", "w", stdout);
  prefix[0] = 0LL;
  int last = 0; 
  for (long long i = 1; i <= 1000000; i++) {
    if (prefix[i - 1] + i * i <= 1000000000000000000LL) {
      prefix[i] = prefix[i - 1] + i * i;
      last = i;  
    }
    else {
      break; 
    }
  }                  
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    std::cin >> x; 
    int lo = 0LL; 
    int hi = last; 
    int ans = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (prefix[mid] <= x) {
        ans = mid;
        lo = mid + 1;   
      }
      else {
        hi = mid - 1;
      }
    }
    std::cout << ans << ' '; 
  }
  return 0; 
}