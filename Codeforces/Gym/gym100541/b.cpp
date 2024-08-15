#include <iostream>
#include <math.h>
const long long mod = 1000000; 
long long n;
int numTest;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    long long ans = 0LL; 
    long long sqrtN = (long long) std::sqrt(n); 
    for (long long i = 1; i <= sqrtN; i++) {
      ans += n / i;
      ans %= mod;   
    }  
    for (long long i = 1; i <= sqrtN; i++) {
      long long r = n / i;
      long long l = std::max(sqrtN + 1, n / (i + 1) + 1);
      if (l <= r) {
        ans += i * (r - l + 1); 
        ans %= mod; 
      }  
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}