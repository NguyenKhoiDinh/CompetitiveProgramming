#include <iostream> 
#include <string> 
#include <math.h> 

struct node {
  int freeOpen = 0, freeClose = 0, maxLength = 0; 
};
std::string s; 

node solve(int L, int R) {
  if (L == R) {
    if (s[L] == '(') {
      return (node) {1, 0, 0}; 
    }
    else if (s[L] == ')') {
      return (node) {0, 1, 0}; 
    }
    else {
      return (node) {0, 0, 0}; 
    }
  }
  int mid = (L + R) / 2; 
  node left = solve(L, mid); 
  node right = solve(mid + 1, R); 
  node ret; 
  int correct = std::min(left.freeOpen, right.freeClose); 
  ret.maxLength = left.maxLength + right.maxLength + 2 * correct; 
  ret.freeOpen = left.freeOpen + right.freeOpen - correct; 
  ret.freeClose = left.freeClose + right.freeClose - correct;
  return ret; 
}

int main () {  
  std::cin >> s; 
  int n = (int) s.size(); 
  std::cout << solve(0, n - 1).maxLength; 
  return 0;
}