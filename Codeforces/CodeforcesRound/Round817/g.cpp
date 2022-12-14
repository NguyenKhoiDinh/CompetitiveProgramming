#include <iostream>
const int LIM = (1 << 30); 
int numTest; 
int n; 
int a[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    a[1] = 0; 
    int sumXorEven = 0; 
    for (int i = 2; i <= n - 2; i += 2) {
      a[i] = i; 
      sumXorEven ^= i; 
    }  
    if (n % 2 == 0) {
      a[n] = LIM + sumXorEven; 
    }
    else {
      a[n - 1] = LIM + sumXorEven; 
    }
    int numbOdd = (n + 1) / 2;
    int value = 1; 
    int sumXorOdd = 0; 
    for (int i = (numbOdd % 2 == 0 ? 1 : 3); i <= n - 2; i += 2) {
      a[i] = value;
      sumXorOdd ^= value; 
      value += 2;
    }
    if (n % 2 == 0) {
      a[n - 1] = LIM + sumXorOdd; 
    }
    else {
      a[n] = LIM + sumXorOdd; 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << a[i] << ' '; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}