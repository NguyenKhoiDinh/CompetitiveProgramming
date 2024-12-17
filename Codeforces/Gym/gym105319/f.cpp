#include <iostream>
#include <string> 
int numTest; 
std::string s; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s; 
    if (s == "BdnaDars") {
      std::cout << "Enough!";
    }
    else {
      std::cout << "OK"; 
    }
    std::cout << std::endl;
  }
  return 0; 
}