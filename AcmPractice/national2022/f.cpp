#include <iostream>
#include <string> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string fullname, firstname, lastname; 
    std::cin >> fullname >> firstname >> lastname; 
    std::cout << (fullname == lastname + firstname ? "YES" : "NO") << std::endl;
  }
  return 0; 
}