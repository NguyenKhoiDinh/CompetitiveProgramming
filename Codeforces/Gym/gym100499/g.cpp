#include <iostream> 
#include <string> 
#include <queue> 
#include <utility> 
#include <math.h>
int numTest; 
int n; 
int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::vector <std::string> a; 
    a.resize(2 * n + 1);
    for (int i = 0; i < 2 * n + 1; i++) {
      for (int j = 0; j < 2 * n + 1; j++) {
        a[i] += 'w'; 
      }
    }
    a[n][n] = 'b'; 
    for (int i = 0; i < 2 * n + 1; i++) {
      for (int j = 0; j < 2 * n + 1; j++) {
        if ((std::abs(i - n) + std::abs(j - n)) % 3 == 0) {
          a[i][j] = 'b';
        }
      }
    }
    for (int i = 0; i < 2 * n + 1; i++) {
      std::cout << a[i] << std::endl;
    }
  }
  return 0; 
}