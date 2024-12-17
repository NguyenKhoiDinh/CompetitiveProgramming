#include <iostream>
#include <queue> 
#include <algorithm> 
#include <vector>
#include <functional>
#include <set>
#include <utility>  
int numTest; 
int n; 
int a[200005], b[200005]; 
std::set <int> myset[3]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int x = 0; x < 3; x++) {
      myset[x].clear(); 
    }
    std::cin >> n; 
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      myset[a[i]].insert(i); 
      b[i] = a[i];
    }
    std::sort(b, b + n);
    std::vector <std::pair <int, int> > ans; 
    for (int i = n - 1; i >= 0; i--) {
      while (a[i] != b[i]) {
        int value = a[i]; 
        std::set <int>::iterator it = myset[value + 1].begin();
        int pos = *it;
        ans.push_back(std::make_pair(pos, i)); 
        myset[value].erase(myset[a[i]].find(i));
        myset[value + 1].erase(it);      
        std::swap(a[i], a[pos]);
        myset[value].insert(pos);
        myset[value + 1].insert(i);   
      }  
    } 
    std::cout << (int) ans.size() << std::endl;
    for (int i = 0; i < (int) ans.size(); i++) {
      std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << std::endl; 
    }
  }
  return 0; 
}