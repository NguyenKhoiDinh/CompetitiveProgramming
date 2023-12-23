#include <iostream>
int f[1000005]; 

void create() {
  for (int i = 1; i <= 1000000; i++) {
    int p = 2; 
    while (p <= i) {
      f[i] += i / p; 
      p *= 2; 
    }
  }
}

int main () {
  create(); 
  freopen("output.txt", "w", stdout); 
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= i; j++) {
      if (f[i] - f[j] == f[i - j]) {
        std::cout << i << "    " << j << std::endl;
      }
    }
  }
  return 0; 
}