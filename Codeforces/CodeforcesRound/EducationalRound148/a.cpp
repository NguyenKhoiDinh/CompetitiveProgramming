#include <iostream> 
#include <string> 
int numTest; 
int cnt[26]; 
std::string s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s; 
    for (int c = 0; c < 26; c++) {
      cnt[c] = 0; 
    }
    for (int i = 0; i < (int) s.size(); i++) {
      cnt[s[i] - 'a']++; 
    }
    int diff = 0; 
    int posOdd = -1; 
    for (int c = 0; c < 26; c++) {
      if (cnt[c] > 0) {
        diff++; 
        if (cnt[c] % 2 == 1) {
          posOdd = c; 
        }
      }  
    }
    if (diff == 1) {
      std::cout << "NO"; 
    }
    else if (diff > 2) {
      std::cout << "YES"; 
    }
    else {
      if (posOdd == -1) {
        std::cout << "YES"; 
      }
      else {
        std::cout << (cnt[posOdd] > 1 ? "YES" : "NO");
      }
    }
    std::cout << std::endl; 
  }
  return 0; 
}