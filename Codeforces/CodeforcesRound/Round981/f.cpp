#include <iostream>
#include <vector>
const long long mod = 1000000007LL;   
long long n;
int k; 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    long long fibo1 = 1;
    long long fibo2 = 1;
    int len = 2; 
    while (true) {
      long long fibo = (fibo1 + fibo2) % k; 
      len++; 
      if (fibo == 0) {
        break;   
      }
      fibo1 = fibo2;
      fibo2 = fibo;
    }
    if (k == 1) {
      len = 1; 
    }
    std::cout << ((n % mod) * (len % mod)) % mod << std::endl;   
  }
  return 0; 
}

                              
