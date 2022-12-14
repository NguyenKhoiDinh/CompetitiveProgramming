#include <iostream> 

int f[1000005]; 

int main () {
  freopen("output.txt", "w", stdout);
  f[0] = 1; 
  for (int i = 1; i <= 1000000; i++) {
    if (i % 2 == 0) {
      f[i] = f[i / 2] + f[i / 2 - 1];
    } 
    else {
      f[i] = f[(i - 1) / 2]; 
    }
  }
  for (int i = 1; i <= 50; i++) {
    std::cout << f[i] << "     "; 
  }
  int maxi = -1; 
  return 0; 
}