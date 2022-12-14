#include <iostream> 
#include <string> 
int numTest;
std::string a[8]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int i = 0; i < 8; i++) {
      std::cin >> a[i]; 
    } 
    for (int r = 1; r <= 6; r++) {
      for (int c = 1; c <= 6; c++) {
        if (a[r][c] == '#' && a[r - 1][c - 1] == '#' && a[r - 1][c + 1] == '#') {
          std::cout << r + 1 << ' ' << c + 1 << std::endl; 
        }
      }
    }
  }
  return 0;
}