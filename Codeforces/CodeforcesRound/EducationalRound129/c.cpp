#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
int numTest; 
int a[105], b[105]; 
int n; 
std::vector <std::pair <int, int> > ans; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }  
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i]; 
    }
    ans.clear();
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] >= a[j] && b[i] >= b[j]) {
          ans.push_back(std::make_pair(i, j));
          std::swap(a[i], a[j]);
          std::swap(b[i], b[j]);   
        }
      }
    }
    bool check = true;
    for (int i = 2; i <= n; i++) {
      if (a[i] < a[i - 1] || b[i] < b[i - 1]) {
        check = false;
      }
    } 
    if (check == false) {
      std::cout << -1 << std::endl; 
    }
    else {
      std::cout << (int) ans.size() << std::endl;
      for (int i = 0; i < (int) ans.size(); i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
      }
    }
  }
  return 0; 
}