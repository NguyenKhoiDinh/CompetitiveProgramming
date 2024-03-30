#include <iostream>
int a[1000005]; 
int n; 
int prefix[1000005], suffix[1000005]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] | a[i]; 
  }
  for (int i = n; i >= 1; i--) {
    suffix[i] = suffix[i + 1] | a[i]; 
  }
  long long ans = 0LL; 
  for (int i = 1; i < n; i++) {
    int sumOr = prefix[i - 1]; 
    for (int j = i + 1; j <= n; j++) {
      int value = a[i] | a[j]; 
      if (value == (sumOr | suffix[j + 1])) {
        ans++; 
      }
      sumOr |= a[j]; 
    }
  }
  std::cout << 2LL * ans;
  return 0; 
}