#include <iostream>
#include <set>
#include <string> 
int numTest;
int n;        
std::multiset <int> S;
const int VALUE = 2147483647;  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    S.clear(); 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x; 
      S.insert(x); 
    }
    int ans = 0; 
    while (S.empty() == false) {
      std::multiset <int>::iterator it = S.begin(); 
      ans++; 
      int value = *it;
      S.erase(it);  
      int r_value = VALUE ^ value; 
      if (S.find(r_value) != S.end()) {
        it = S.find(r_value);
        S.erase(it);  
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}