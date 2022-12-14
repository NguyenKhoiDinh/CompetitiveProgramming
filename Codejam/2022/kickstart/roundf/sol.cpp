#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
  }
  return 0; 
}