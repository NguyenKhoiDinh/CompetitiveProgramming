#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    std::cout << n % 10 + n / 10 << std::endl;  
  }
  return 0; 
}