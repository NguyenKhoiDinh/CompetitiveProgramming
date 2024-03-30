#include <iostream>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c;
    std::cin >> a >> b >> c; 
    long long ans = a; 
    ans += b / 3; 
    b %= 3; 
    if ((b == 1 && c <= 1) || (b == 2 && c == 0)) {
      std::cout << -1 << std::endl;
      continue; 
    }
    if (b == 1 || b == 2) {
      ans++; 
    }
    if (b == 2) {
      c--;
    }
    else if (b == 1) {
      c -= 2; 
    }
    ans += (c + 2) / 3; 
    std::cout << ans << std::endl;
  }
  return 0; 
}