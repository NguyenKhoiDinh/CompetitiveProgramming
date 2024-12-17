#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    std::cin >> n >> k;
    int numbOdd = 0;
    numbOdd += (n + k) / 2;
    numbOdd -= n / 2;
    std::cout << (numbOdd % 2 == 0 ? "YES" : "NO") << std::endl;   
  }
  return 0; 
}