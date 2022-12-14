#include <iostream>
#include <algorithm>
#include <math.h> 
int numTest; 
long long Pow10[20]; 

int main () {
  Pow10[0] = 1LL;
  for (int i = 1; i <= 18; i++) {
    Pow10[i] = Pow10[i - 1] * 10LL; 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n, m;
    std::cin >> n >> m;
    long long ans = 0LL; 
    for (int x = 0; x <= 18; x++) {
      long long gcd = std::__gcd(Pow10[x], n); 
      long long newn = n / gcd;
      long long newpow10 = Pow10[x] / gcd; 
      if (newpow10 <= m) {
        long long maxMul = m / newpow10;
        ans = maxMul * n * newpow10;  
      }
    }
    std::cout << ans << std::endl;  
  }
  return 0; 
}