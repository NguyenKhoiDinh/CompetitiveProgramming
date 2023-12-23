#include <iostream> 
int numbDivisors[1000005]; 
int n; 

int main () {
  for (int i = 1; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) {
      numbDivisors[j]++; 
    }
  }
  long long ans = 0LL; 
  std::cin >> n; 
  for (int a = 1; a < n; a++) {
    int b = n - a; 
    ans += 1LL * numbDivisors[a] * numbDivisors[b]; 
  }
  std::cout << ans;
  return 0;
}