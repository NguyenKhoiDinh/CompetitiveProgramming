#include <iostream> 
int numTest; 
int f[200005]; 
int sum[200005]; 

int main () {
  for (int i = 1; i <= 200000; i++) {
    int tmp = i; 
    while (tmp > 0) {
      f[i]++;
      tmp /= 3; 
    }
    sum[i] = sum[i - 1] + f[i]; 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << f[l] + sum[r] - sum[l - 1] << std::endl;       
  }
  return 0; 
}