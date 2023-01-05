#include <iostream> 
#include <string>    
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::string N; 
    std::cin >> N;
    int sum = 0; 
    for (int i = 0; i < (int) N.size(); i++) {
      (sum += (N[i] - '0')) %= 9; 
    }
    sum = (9 - sum) % 9;
    bool canWrite = (sum != 0);
    bool found = false; 
    for (int i = 0; i < (int) N.size(); i++) {
      if (sum + '0' < N[i] && canWrite == true && found == false) {
        std::cout << sum; 
        found = true;
      } 
      canWrite = true; 
      std::cout << N[i]; 
    } 
    if (found == false) {
      std::cout << sum;
    }
    std::cout << std::endl; 
  }
  return 0; 
}