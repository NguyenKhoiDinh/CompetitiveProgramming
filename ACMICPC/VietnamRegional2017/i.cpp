#include <iostream>
#include <string>
#include <set> 
int n; 
std::set <std::string> S; 

int main () {                      
  std::cin >> n;
  int numTeams = 0; 
  for (int i = 1; i <= n; i++) {
    if (numTeams == 12) {
      break;
    }
    std::string s1, s2;
    std::cin >> s1 >> s2; 
    if (S.find(s1) == S.end()) {
      numTeams++; 
      std::cout << s1 << ' ' << s2 << std::endl; 
      S.insert(s1);
    }
  }
  return 0; 
}