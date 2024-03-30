#include <iostream>
int numTest; 
int n, x; 
int a[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> x;
    int pos1 = -1; 
    int posx = -1; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      if (a[i] == 1) {
        pos1 = i; 
      }
      if (a[i] == x) {
        posx = i; 
      }
    }
    if (x == 1) {
      std::cout << 1 << std::endl;
      std::cout << 1 << ' ' << pos1 << std::endl;
      continue; 
    }
    int l = 1;
    int r = n + 1; 
    bool check = false; 
    while (r - l > 1) {
      int mid = (l + r) / 2; 
      if (a[mid] <= x) {
        l = mid; 
        if (a[mid] == x) {
          check = true; 
        }
      }
      else {
        r = mid; 
      }
    }
    if (check == false) {
      std::cout << 1 << std::endl;
      std::cout << posx << ' ' << l << std::endl; 
    }
    else {
      std::cout << 2 << std::endl; 
      std::cout << posx << ' ' << pos1 << std::endl; 
      std::cout << pos1 << ' ' << l << std::endl;
    }
  }
  return 0; 
}