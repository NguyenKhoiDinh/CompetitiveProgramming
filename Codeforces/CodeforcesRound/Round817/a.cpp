#include <iostream>
#include <string>
#include <algorithm>
int numTest; 
std::string s; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cin >> s; 
    std::string st = "Timru";
    bool found = false; 
    do {
      if (st == s) {
        found = true; 
        std::cout << "YES" << std::endl;
        break;    
      }
    }
    while (std::next_permutation(st.begin(), st.end())); 
    if (found == false) {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}