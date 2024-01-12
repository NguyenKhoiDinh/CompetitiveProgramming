#include <iostream> 

int numTest; 
long long fibo[50]; 
void init() {
  fibo[0] = 1LL; 
  fibo[1] = 1LL; 
  for (int i = 2; i <= 45; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
}
int main () {
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    long long x, y;
    std::cin >> n >> x >> y; 
    long long r = fibo[n]; 
    long long c = fibo[n + 1]; 
    while (r != c) {
      if (c > r) {
        if (y <= c - r || y > r) {
          c -= r; 
        }  
        else {
          break; 
        }
        if (y > r) {
          y -= r; 
        }
      }
      else {
        if (x <= r - c || x > c) {
          r -= c; 
        }
        else {
          break; 
        }
        if (x > c) {
          x -= c; 
        }
      }
    }
    std::cout << (c != r ? "NO" : "YES") << std::endl; 
  }
  return 0;   
}