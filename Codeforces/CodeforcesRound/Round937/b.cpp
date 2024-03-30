#include <iostream>
int numTest; 
char a[45][45]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n; 
    std::cin >> n; 
    bool flag = true; 
    for (int i = 1; i <= 2 * n; i += 2) {
      bool change = true; 
      for (int j = 1; j <= 2 * n; j += 2) {
        if (flag == change) {
          a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = '#';  
        }  
        else {
          a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = '.';  
        }
        change = !change; 
      }
      flag = !flag; 
    }
    for (int i = 1; i <= 2 * n; i++) {
      for (int j = 1; j <= 2 * n; j++) {
        std::cout << a[i][j];
      }
      std::cout << std::endl;
    }
  }
  return 0; 
}