#include <iostream> 

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n; 
    long long ans = 0LL; 
    if (n % 2 == 1) {
      ans += (n + 1) / 2; 
      n--; 
    }
    long long half = n / 2; 
    ans += half * (half + 1);
    std::cout << ans << std::endl; 
  }
  return 0; 
}