#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility> 
int numTest; 
int n; 
std::pair <int, int> a[200005];    
std::map <int, int> value; 
std::map <int, std::vector <int> > pos; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    value.clear(); 
    pos.clear();
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].first;
      if (value.find(a[i].first / 4) == value.end()) {
        value[a[i].first / 4] = i;
      }
      a[i].second = value[a[i].first / 4];
      pos[a[i].second].push_back(a[i].first);    
    }
    for (std::map <int, std::vector <int> >::iterator it = pos.begin(); it != pos.end(); it++) {
      std::vector <int> &v = it->second; 
      std::sort(v.begin(), v.end());
      std::reverse(v.begin(), v.end()); 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << pos[a[i].second].back() << ' ';
      pos[a[i].second].pop_back();
    }   
    std::cout << std::endl; 
  }
  return 0; 
}