#include <iostream>
const long long mod = 998244353LL; 

int main () {
  long long a, b, c;
  std::cin >> a >> b >> c; 
  long long d = a - b; 
  long long k = 2LL * c + 1; 
  d %= mod; 
  k %= mod; 
  std::cout << (d * k) % mod;
  return 0; 
}