#include <iostream>
#include <math.h>
int numTest, A, B, X, Y; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> A >> B >> X >> Y;
    int ans = 1000005; 
    for (int D = 0; D <= 10000; D++) {
      if ((B * Y - A * X + D * (X + Y)) % X == 0) {
        int sum = (B * Y - A * X + D * (X + Y)) / X; 
        if (sum - D >= 0) {
          ans = std::min(ans, sum);  
        }
      }
    }
    std::cout << (ans == 1000005 ? -1 : ans) << std::endl;
  }
  return 0; 
}