#include <iostream>

int main () {
  freopen("tong.inp", "r", stdin);
  freopen("tong.out", "w", stdout); 
  long long n;
  std::cin >> n;
  std::cout << n * (n - 1) / 2;
  return 0; 
}