#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>
std::vector <std::pair <int, int> > v;
std::vector <int> hl, hr;  

int main () {
  int n; 
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    char type; 
    int t, m, a; 
    std::cin >> type >> t >> m >> a; 
    t -= a; 
    if (type == 'h') {
      hl.push_back(t); 
      hr.push_back(t + m - 1); 
    }
    else {
      v.push_back(std::make_pair(t, t + m - 1)); 
    }
  }
  std::sort(hl.begin(), hl.end()); 
  std::sort(hr.begin(), hr.end()); 
  long long ans = 0LL; 
  for (int i = 0; i < (int) v.size(); i++) {
    int l = v[i].first;
    int r = v[i].second; 
    int cr = std::upper_bound(hl.begin(), hl.end(), r) - hl.begin();
    int cl = std::upper_bound(hr.begin(), hr.end(), l - 1) - hr.begin();
    ans += cr - cl; 
  }
  std::cout << ans;
  return 0; 
}