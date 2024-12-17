#include <iostream> 
int G, W, R, T; 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> G >> W >> R >> T; 
    int l = 0;
    int state = 0; 
    while (true) {
      int r = l + G; 
      if (state == 1) {
        r = l + W; 
      } 
      else if (state == 2) {
        r = l + R; 
      }
      if (T < r) {
        if (state == 0) {
          std::cout << "Guiding Beat" << std::endl; 
        }
        else if (state == 1) {
          std::cout << "Warning Beat" << std::endl;
        }
        else {
          std::cout << "Resting Phase" << std::endl; 
        }
        break; 
      }
      l = r; 
      state++;
      state %= 3; 
    }
  } 
  return 0; 
}