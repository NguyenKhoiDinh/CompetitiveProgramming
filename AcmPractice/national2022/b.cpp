#include <iostream>
#include <unordered_set>
#include <bitset>
#include <vector>
#include <string>
int n, m, k; 

int main () {
  std::cin >> n >> m >> k; 
  const int LIM_BIT = 300; 
  std::vector <std::bitset <LIM_BIT> > a(n);
  std::unordered_set <std::bitset <LIM_BIT> > myset; 
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s; 
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
        a[i].set(j, 1); 
      }
    }
    myset.insert(a[i]); 
  }
  if (k == 1) {
    std::cout << "YES";
    return 0; 
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        std::bitset <LIM_BIT> mask = a[i] & a[j];
        mask |= (a[j] & a[k]);
        mask |= (a[k] & a[i]); 
        if (myset.find(mask) == myset.end()) {
          std::cout << "NO";
          return 0; 
        }
      }
    }
  }
  std::cout << "YES";
  return 0; 
}