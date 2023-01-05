#include <iostream> 
#include <math.h>
#include <iomanip>
int numTest; 
const double PI = std::acos(-1); 
long long R, A, B; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cin >> R >> A >> B;
    double sum = 0.0;
    bool flag = true; 
    while (R > 0) {
      sum += R * R; 
      if (flag == true) {
        R *= A; 
      }
      else {
        R /= B; 
      }
      flag = !flag; 
    }  
    std::cout << std::fixed << std::setprecision(12) << sum * PI << std::endl; 
  }
  return 0; 
}