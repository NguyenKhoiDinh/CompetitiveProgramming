#include <iostream> 
int numTest; 
long long a, b, n;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> a >> b >> n; 
    if (a % b == 0) {
      std::cout << -1 << std::endl;
      continue; 
    }
    long long d = n / a; 
    if (n % a != 0) {
      d++; 
    }
    long long ans = d * a; 
    if (ans % b == 0) {
      ans += a; 
    }
    std::cout << ans << std::endl; 
  }
  return 0;
}