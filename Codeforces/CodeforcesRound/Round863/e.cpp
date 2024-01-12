#include <iostream> 

long long ways[17]; 
int numTest; 
void init() {
  ways[0] = 1LL; 
  for (int i = 1; i <= 16; i++) {
    ways[i] = 1; 
    for (int j = 1; j <= i; j++) {
      ways[i] *= 9LL; 
    }
  } 
}
long long k; 
int main () {
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> k;
    int lenDigits = 0; 
    for (int len = 1; len <= 16; len++) {
      long long totalNumbers = ways[len] - ways[len - 1];
      if (totalNumbers >= k) {
        lenDigits = len; 
        break; 
      }  
      else {
        k -= totalNumbers; 
      }
    }    
    for (int i = 1; i <= lenDigits; i++) {
      for (int d = (i == 1); d <= 9; d++) {
        if (d == 4) {
          continue; 
        }
        if (ways[lenDigits - i] >= k) {
          std::cout << d; 
          break;
        }  
        else {
          k -= ways[lenDigits - i]; 
        }
      }  
    }
    std::cout << std::endl; 
  }
  return 0;   
}