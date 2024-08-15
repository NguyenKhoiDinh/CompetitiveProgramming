#include <iostream>
#include <vector>
int n;
int a[200005]; 

int main () {
  std::cin >> n;
  bool dir = false;
  int ans = 0; 
  std::vector <int> a; 
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x; 
    if (x == 0 || i == 1) {
      a.push_back(x); 
    }
    else if (x == 1 && a.back() == 0) {
      a.push_back(x); 
    }
    else if (x == 2) {
      if (a.back() >= 1) {
        a.pop_back(); 
      }  
      a.push_back(x); 
    }
  }
  for (int i = 0; i < (int) a.size(); i++) {
    if (a[i] == 0) {
      ans++; 
    }
    else {
      if (i == 0 || a[i - 1] < 0) {
        ans++; 
      }
      else if (a[i] == 1) {
        continue; 
      }
      if (i < n - 1) {
        a[++i]--;
      }
    }
  }
  std::cout << ans;
  return 0; 
}