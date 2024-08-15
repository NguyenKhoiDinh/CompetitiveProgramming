#include <iostream>
#include <math.h>
int numTest; 
int na, nb;
int a[55], b[55]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> na;
    for (int i = 1; i <= na; i++) {
      std::cin >> a[i];
    }
    std::cin >> nb;
    for (int i = 1; i <= nb; i++) {
      std::cin >> b[i]; 
    }
    int maxa = a[1]; 
    for (int i = 2; i <= na; i++) {
      maxa = std::max(maxa, a[i]); 
    }
    int maxb = b[1]; 
    for (int i = 2; i <= nb; i++) {
      maxb = std::max(maxb, b[i]); 
    }
    std::cout << (maxa < maxb ? "Bob" : "Alice") << std::endl;
    std::cout << (maxa > maxb ? "Alice" : "Bob") << std::endl;
  }
  return 0; 
}