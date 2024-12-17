#include <iostream>
#include <string> 
#include <algorithm>
#include <math.h> 
std::string s;
int n;  
int countY = 0; 
bool checkVowel(char ch) {
  return (ch == 'A' || ch == 'I' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int main () {
  std::cin >> s;
  n = (int) s.size();
  int countVowels = 0;
  int countConsonants = 0;  
  int countY = 0; 
  int countN = 0;
  int countG = 0; 
  for (int i = 0; i < n; i++) {
    if (checkVowel(s[i]) == true) {
      countVowels++;
    }
    if (checkVowel(s[i]) == false) {
      countConsonants++; 
    }
    if (s[i] == 'Y') {
      countY++;
    }
    if (s[i] == 'N') {
      countN++;
    }
    if (s[i] == 'G') {
      countG++; 
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (countVowels + countY < i) {
      break;
    }
    int numb = countConsonants - std::max(0, i - countVowels); 
    if (i * 2 > numb) {
      break;
    }
    ans = std::min(numb, 2 * i + std::min(2 * i, std::min(countN, countG))) + i;
  }
  std::cout << ans; 
  return 0; 
}