#include <iostream>
int n;
int a[205], b[205], c[205]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i] >> c[i]; 
  }
  for (int i = 1; i <= n; i++) {
    int total = 0; 
    bool found = false; 
    for (int j = 1; j <= n; j++) {
      if (j != i) {
        if (a[j] == a[i]) {
          found = true; 
          break;
        }  
      }
    }
    if (found == false) {
      total += a[i]; 
    }
    found = false; 
    for (int j = 1; j <= n; j++) {
      if (j != i) {
        if (b[j] == b[i]) {
          found = true; 
          break;
        }  
      }
    }
    if (found == false) {
      total += b[i]; 
    }
    found = false; 
    for (int j = 1; j <= n; j++) {
      if (j != i) {
        if (c[j] == c[i]) {
          found = true; 
          break;
        }  
      }
    }
    if (found == false) {
      total += c[i]; 
    }
    std::cout << total << std::endl;
  }
  return 0; 
}