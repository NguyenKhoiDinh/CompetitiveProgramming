#include <iostream> 
#include <set>
#include <math.h>
#include <algorithm>
int grundy[105]; 

int main () {
  freopen("output.txt", "w", stdout); 
  for (int i = 1; i <= 100; i++) {
    std::set <int> S; 
    for (int j = 1; j <= i; j++) {
      if (std::__gcd(i, j) == 1) {
        S.insert(grundy[i - j]);
      }     
    }
    for (int mex = 0; ; mex++) {
      std::set <int>::iterator it = S.find(mex); 
      if (it == S.end()) {
        grundy[i] = mex;
        break; 
      }
    }
  }
  for (int i = 0; i <= 100; i++) {
    std::cout << grundy[i] << ' ';
  }
  return 0; 
}