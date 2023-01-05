#include <iostream>
#include <math.h>

using namespace std; 
int numTest; 
long long N; 

long long rev(long long N) {
  long long ret = 0LL; 
  while (N > 0) {
    int r = N % 10;
    N /= 10; 
    ret = ret * 10LL + r; 
  }
  return ret; 
}

bool check(long long N) {
  return N == rev(N); 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> N; 
    int ans = 0; 
    for (long long i = 1; i <= (long long) std::sqrt(N); i++) {
      if (N % i == 0) {
        long long a = i; 
        if (check(a) == true) {
          ans++; 
        }
        long long b = N / i; 
        if (b != a && check(b) == true) {
          ans++; 
        }
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}