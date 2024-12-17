#include <iostream> 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    int pos = 0;
    bool check = true;
    int i = 1; 
    while (-n <= pos && pos <= n) {
      if (check == true) {
        pos -= 2 * i - 1; 
      }
      else {
        pos += 2 * i - 1; 
      }
      i++;
      check = !check;  
    }  
    std::cout << (check == true ? "Kosuke" : "Sakurako") << std::endl;
  }
  return 0; 
}