#include <iostream> 
#include <fstream> 
int numTest; 
int R, C; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": " << std::endl; 
    std::cin >> R >> C; 
    for (int i = 1; i <= 2 * R + 1; i++) {
      for (int j = 1; j <= 2 * C + 1; j++) {
        if (i <= 2 && j <= 2) {
          std::cout << '.'; 
        }
        else if (i % 2 == 1) {
          if (j % 2 == 0) {
            std::cout << '-'; 
          }
          else {
            std::cout << '+'; 
          }
        }
        else {
          if (j % 2 == 0) {
            std::cout << '.'; 
          }
          else {
            std::cout << '|'; 
          }
        }
      }
      std::cout << std::endl; 
    }
  }
  return 0; 
}