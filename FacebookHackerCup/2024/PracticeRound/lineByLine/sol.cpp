#include <iostream>
#include <math.h> 
#include <iomanip> 
int numTest; 
int n;
long double P; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout); 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> P; 
    long double save_P = P; 
    P /= 100.0000; 
    P = std::pow(P, 1.0 * (n - 1)); 
    long double new_P = std::pow(P, 1.0 / (long double) n);
    new_P *= 100.0000;
    std::cout << std::fixed << std::setprecision(20) << new_P - save_P << std::endl; 
  }
  return 0; 
}