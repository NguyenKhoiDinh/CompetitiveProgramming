#include <iostream> 

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long N;
    std::cin >> N;
    long long X = N; 
    long long firstBit = -1; 
    for (long long i = 0; i < 64; i++) {
      if ((X & (1LL << i)) > 0) {
        firstBit = i; 
      }
    }
    X = 0; 
    for (long long j = firstBit - 1; j >= 0; j--) {
      X ^= (1LL << j); 
    }
    std::cout << X << std::endl;
  }
  return 0; 
}