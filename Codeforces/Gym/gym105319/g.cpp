#include <iostream> 
bool isPrime[1000005];
bool ok[1000005];  
void init() {
  for (int i = 2; i <= 1000000; i++) {
    isPrime[i] = true; 
  }  
  for (int i = 2; i * i <= 1000000; i++) {
    for (int j = i * i; j <= 1000000; j += i) {
      isPrime[j] = false; 
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {
      for (int j = i; j <= 1000000 / i; j *= i) {
        ok[j] = true; 
      }
    }
  }
}
int calc(int x) {
  int ret = 0; 
  for (int i = 2; i <= x; i *= 2) {
    ret += x / i; 
  }
  return ret; 
}

int main () {
  init();
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n; 
    if (ok[n] == false) {
      if (n % 2 == 1) {
        std::cout << 2 << std::endl; 
      } 
      else {
        int total = calc(n) - calc(n / 2) - calc(n / 2);
        if (total == 0) {
          std::cout << 1 << std::endl; 
        }
        else {
          std::cout << 2 << std::endl; 
        }
      }
    }
    else {
      if (n % 2 == 1) {
        std::cout << 4 << std::endl; 
      }
      else {
        int total = calc(n) - calc(n / 2) - calc(n / 2) - 1;
        std::cout << calc(n) << "     " << calc(n / 2) << std::endl;
        if (total == 0) {
          std::cout << 2 << std::endl;
        }  
        else {
          std::cout << 4 << std::endl; 
        }
      }
    }
  }
  return 0; 
}