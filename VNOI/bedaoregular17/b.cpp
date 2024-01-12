#include <iostream>
#include <vector> 
bool isPrime[1000005]; 
std::vector <int> listPrime[1000005]; 
std::vector <int> validNumbers; 

void erathones() {
  for (int i = 1; i <= 1000000; i++) {
    isPrime[i] = true;   
  }
  isPrime[1] = false;
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i] == true) {   
      if ((int) listPrime[i].size() < 2) {
        listPrime[i].push_back(i);
      }
      for (int j = 2 * i; j <= 1000000; j += i) {
        if ((int) listPrime[j].size() < 2) {
          listPrime[j].push_back(i);
        } 
        isPrime[j] = false; 
      }
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if ((int) listPrime[i].size() < 2) {
      continue; 
    }
    if (i == listPrime[i][0] * listPrime[i][1]) {
      validNumbers.push_back(i); 
    }
  }
}

int main () {
  erathones(); 
  long long n;
  std::cin >> n;
  int ans = 0;  
  for (int i = 0; i < (int) validNumbers.size(); i++) {
    long long value = validNumbers[i];
    if (value * value * value > n) {
      break; 
    }
    ans++; 
  }
  std::cout << ans;
  return 0;
}