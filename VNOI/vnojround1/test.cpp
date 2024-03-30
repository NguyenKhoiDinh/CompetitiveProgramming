#include <iostream>
#include <vector>
const int LIM = 10000000; 
bool isPrime[10000007]; 
std::vector <int> listPrimes; 

void erathones() {
  for (int i = 1; i <= LIM; i++) {
    isPrime[i] = true; 
  }
  isPrime[1] = false; 
  for (int i = 2; i * i <= LIM; i++) {
    if (isPrime[i] == false) {
      continue; 
    }
    for (int j = i * i; j <= LIM; j += i) {
      isPrime[j] = false; 
    }
  }
  for (int i = 2; i <= LIM; i++) {
    if (isPrime[i] == true) {
      listPrimes.push_back(i); 
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  erathones();
  std::cout << 663213 << std::endl;
  for (int i = 1002; i < 664215; i++) {
    std::cout << listPrimes[i] << ' ';
  }
  return 0; 
}