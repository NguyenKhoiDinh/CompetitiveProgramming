#include <iostream> 

int main () {
  int A, B;
  std::cin >> A >> B;
  long long ans = 0; 
  while (A != B) {
    if (A < B) {
      ans += B - A; 
      A = B; 
    }
    else {
      if (A % 2 == 1) {
        A++; 
        ans++;  
      }
      else {
        A /= 2;
        ans++; 
      }
    }
  }
  std::cout << ans;
  return 0; 
}                  
