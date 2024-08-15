#include <iostream>
#include <vector> 
#include <utility>
int a[55]; 

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::vector <std::pair <int, int> > ans; 
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }  
    for (int p = 1; p <= n; p++) {
      int pos = -1; 
      for (int i = 1; i <= n; i++) {
        if (a[i] == p) {
          pos = i;
          break;  
        }
      }
      if (pos > p) {
        ans.push_back(std::make_pair(pos, n + 1));
        for (int i = pos - 1; i >= p; i--) {
          ans.push_back(std::make_pair(i, i + 1));
          a[i + 1] = a[i];  
        }  
        a[p] = p;
        ans.push_back(std::make_pair(n + 1, p));  
      }
    }
    std::cout << (int) ans.size() << std::endl;
    for (int i = 0; i < (int) ans.size(); i++) {
      std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
    }
  }
  return 0; 
}