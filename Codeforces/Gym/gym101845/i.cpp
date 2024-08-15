#include <iostream>

int main () {
  int n, m; 
  long long k; 
  std::cin >> n >> m; 
  for (int i = 1; i <= m; i++) {
    long long num;
    std::cin >> num >> k;
    long long ans = 0LL;
    k %= n;
    for (long long i = 0; i < n; i++) {
      if ((num & (1LL << i)) > 0) {
        int pos = i; 
        pos += k;
        pos %= n; 
        ans |= (1LL << pos); 
      }
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}