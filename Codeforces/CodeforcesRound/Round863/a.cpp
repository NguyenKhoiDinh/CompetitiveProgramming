#include <iostream> 
#include <string> 
#include <math.h>

std::string addDigit(const std::string &N, int d, int pos) {
  std::string ret = ""; 
  for (int i = 0; i < pos; i++) {
    ret += N[i]; 
  }
  ret += (char) (d + '0'); 
  for (int i = pos; i < (int) N.size(); i++) {
    ret += N[i]; 
  }
  return ret; 
} 

int numTest; 
int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int len, d;
    std::string N; 
    std::cin >> len >> d; 
    std::cin >> N; 
    std::string ans = "!"; 
    if (d > N[0] - '0') {
      ans = addDigit(N, d, 0);   
    } 
    if (ans == "!") {
      for (int i = 1; i < len; i++) {
        if (d <= N[i - 1] - '0') {
          if (d <= N[i] - '0') {
            continue; 
          } 
          ans = addDigit(N, d, i); 
          break; 
        }
      }
    }
    if (ans == "!") {
      ans = addDigit(N, d, len); 
    }
    std::cout << ans << std::endl;
  }
  return 0;   
}