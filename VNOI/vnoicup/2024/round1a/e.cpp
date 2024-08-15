#include <iostream>
#include <string> 
#include <set>
#include <utility>
#include <unordered_map> 
int numTest;
int n; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    std::unordered_map <long long, int> S; 
    int x, y, l, c; 
    std::cin >> x >> y >> l >> c; 
    l++; 
    bool flag = true; 
    while (l--) {
      S[1000007LL * x + y] = true; 
      if (flag == true) {
        if (c == 0) {
          x++;     
        }
        else {
          y++; 
        }
      }
      else {
        if (c == 0) {
          y++;
        }
        else {
          x++; 
        }
      }
      flag = !flag; 
    }
    std::cin >> x >> y >> l >> c; 
    l++; 
    flag = true; 
    int ans = 0; 
    while (l--) {
      if (S[1000007 * x + y] == true) {
        ans++;   
      }
      if (flag == true) {
        if (c == 0) {
          x++;
        }
        else {
          y++; 
        }
      }
      else {
        if (c == 0) {
          y++;
        }
        else {
          x++;
        }
      }
      flag = !flag;
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}