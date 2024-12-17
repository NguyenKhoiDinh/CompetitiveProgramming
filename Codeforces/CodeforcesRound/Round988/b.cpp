#include <iostream>
#include <set> 
int numTest;
int a[200005];  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int k;
    std::cin >> k;
    for (int i = 1; i <= k; i++) {
      std::cin >> a[i]; 
    } 
    std::set <int> S; 
    int sz = k - 2; 
    int ansn = -1;
    int ansm = -1; 
    for (int i = 1; i <= k; i++) {
      if (sz % a[i] == 0) {
        if (S.find(sz / a[i]) != S.end()) {
          ansn = a[i];
          ansm = sz / a[i]; 
          break; 
        }  
      }
      S.insert(a[i]);   
    }
    std::cout << ansn << ' ' << ansm << std::endl;
  }
  return 0; 
}