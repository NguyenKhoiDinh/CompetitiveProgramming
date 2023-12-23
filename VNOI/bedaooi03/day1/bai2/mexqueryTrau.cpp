#include <iostream>
#include <algorithm>
#include <vector>
std::vector <int> a;
int n, numQueries;

int main () {
  freopen("mexquery.inp", "r", stdin);
  freopen("mexquery.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  if (n <= 1000) { 
    std::cin >> numQueries;
    for (int query = 1; query <= numQueries; query++) {
      int type;
      std::cin >> type;
      if (type == 1) {
        int l, r, increasing; 
        std::cin >> l >> r >> increasing;
        l--;
        r--;
        std::sort(a.begin() + l, a.begin() + r + 1); 
        if (increasing == 2) {
          std::reverse(a.begin() + l, a.begin() + r + 1); 
        }
      }
      else {
        int l, r;
        std::cin >> l >> r;
        l--;
        r--;
        std::vector <bool> v;
        v.resize(31, false); 
        int ans = 31; 
        for (int i = l; i <= r; i++) {
          v[a[i]] = true; 
        }
        for (int i = 0; i <= 30; i++) {
          if (v[i] == false) {
            ans = i;
            break;  
          }
        }
        std::cout << ans << std::endl;
      }  
    }
  }
  return 0; 
}