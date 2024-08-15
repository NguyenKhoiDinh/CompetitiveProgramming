#include <iostream> 
int n; 
long long p[105]; 
long long C; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  long long mul = 1LL; 
  for (int i = 1; i <= n; i++) {
    if (mul <= 1000000000000000007LL / p[i]) {
      mul *= p[i];
    }
    else {
      mul = 1000000000000000007LL;
      break; 
    }
  }
  std::cin >> C; 
  for (long long X = 1; X <= 1000000; X++) {
    if ((X * X * X) % mul == C) {
      std::cout << X;
      return 0;
    } 
  }
  return 0; 
}