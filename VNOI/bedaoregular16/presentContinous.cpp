#include <iostream>
#include <string> 
std::string name; 

int main () {
  std::cin >> name; 
  if (name == "I") {
    std::cout << "am"; 
  }
  else if (name == "They" || name == "You" || name == "We") {
    std::cout << "are"; 
  }
  else {
    std::cout << "is"; 
  }
  return 0;
}