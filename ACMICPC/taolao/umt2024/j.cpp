#include <iostream>
#include <set> 
#include <algorithm>
#include <utility> 
int n; 
std::pair <int, int> a[1005]; 
std::set <std::pair <int, int> > S; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second; 
    S.insert(a[i]); 
  }
  int ans = 0; 
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int d1 = std::abs(a[i].first - a[j].first);
      int d2 = std::abs(a[i].second - a[j].second);
      if (d1 > 0 && d1 == d2) {
        std::pair <int, int> other1 = std::make_pair(a[i].first, a[j].second);
        std::pair <int, int> other2 = std::make_pair(a[j].first, a[i].second);
        if (S.find(other1) != S.end() && S.find(other2) != S.end()) {
          ans++; 
        }  
      } 
    }
  } 
  std::cout << ans / 2; 
  return 0; 
}