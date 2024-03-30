#include <iostream>
int numTest; 
int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += x % 10;
    x /= 10; 
  }
  return ret; 
}
int f[200005]; 

int main () {
  for (int i = 1; i <= 200005; i++) {
    f[i] = f[i - 1] + sum(i); 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    int n;
    std::cin >> n;
    std::cout << f[n] << std::endl;
  }
  return 0; 
}