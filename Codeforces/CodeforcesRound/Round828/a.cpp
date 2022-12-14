#include <iostream> 
#include <set> 
int numTest; 
std::set <char> myset[55]; 
int a[55]; 
std::string s;
int n;  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int i = 0; i <= 50; i++) {
      myset[i].clear(); 
    }  
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::cin >> s; 
    for (int i = 1; i <= n; i++) {
      myset[a[i]].insert(s[i - 1]); 
    }
    bool ans = true; 
    for (int i = 1; i <= 50; i++) {
      if ((int) myset[i].size() > 1) {
        ans = false;
        break;   
      }
    }
    if (ans == true) {
      std::cout << "YES"; 
    }
    else {
      std::cout << "NO"; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}