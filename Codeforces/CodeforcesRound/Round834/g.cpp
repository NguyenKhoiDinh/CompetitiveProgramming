#include <iostream>
#include <cstring> 
#include <set>
int numTest; 
int n;                 
std::set <int> myset; 
int position[200005]; 
int ans[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    myset.clear(); 
    std::memset(position, 0, sizeof(position));
    std::cin >> n;
    for (int i = 1; i <= n / 2; i++) {
      int x; 
      std::cin >> x; 
      position[x] = i; 
    }
    bool check = true;  
    for (int i = n; i >= 1; i--) {
      if (position[i] != 0) {
        ans[2 * position[i]] = i;
        myset.insert(2 * position[i] - 1);   
      }
      else {
        if (myset.empty() == true) {
          check = false; 
          break; 
        }
        std::set <int>::iterator it = myset.end();
        it--; 
        ans[*it] = i;
        myset.erase(it); 
      }
    }
    if (check == false) {
      std::cout << -1 << std::endl; 
    }
    else {
      for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " "; 
      }
      std::cout << std::endl;
    }
  }
  return 0; 
}