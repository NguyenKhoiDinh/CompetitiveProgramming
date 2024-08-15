#include <iostream>
bool isPrime[1000005];
int f[1000005]; 
int numTest;
int n;  
void erathones() {
  for (int i = 2; i <= 1000000; i++) {
    isPrime[i] = true; 
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      for (int j = 2 * i; j <= 1000000; j += i) {
        isPrime[j] = false; 
      }
    }
  }
  f[1] = 1; 
  for (int i = 2; i <= 1000000; i++) {
    f[i] = f[i - 1]; 
    if (isPrime[i] == true) {
      f[i]++; 
    }
  }
}

int main () {
  erathones();
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cout << "Case #" << testCase << ": ";  
    std::cout << f[n] << std::endl; 
  }
  return 0; 
}