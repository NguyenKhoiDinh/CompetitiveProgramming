#include <iostream> 
#include <string>
#include <set> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    std::set <std::string> S; 
    for (int i = 0; i < n - 1; i++) {
      std::string st = "";
      st += s[i];
      st += s[i + 1]; 
      S.insert(st); 
    }
    std::cout << (int) S.size() << std::endl;
  }
  return 0; 
}