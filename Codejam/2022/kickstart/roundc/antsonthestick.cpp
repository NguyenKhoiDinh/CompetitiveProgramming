#include <iostream>
#include <utility>
#include <vector>
#include <algorithm> 
int numTest; 
int n, L; 
std::vector <std::pair <int, int> > a, b, ans; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> L; 
    a.clear();
    b.clear();
    ans.clear();
    for (int i = 1; i <= n; i++) {
      std::pair <int, int> element; 
      std::cin >> element.first >> element.second; 
      a.push_back(std::make_pair(element.first, i)); 
      if (element.second == 0) {
        b.push_back(element); 
      }
      else {
        b.push_back(std::make_pair(L - element.first, element.second)); 
      }
    }
    std::sort(a.begin(), a.end()); 
    std::sort(b.begin(), b.end()); 
    int l = 0; 
    int r = n - 1; 
    for (int i = 0; i < n; i++) {
      int index = (b[i].second == 0 ? a[l++].second : a[r--].second);
      ans.push_back(std::make_pair(b[i].first, index));  
    }
    std::sort(ans.begin(), ans.end()); 
    for (int i = 0; i < n; i++) {
      std::cout << ans[i].second << ' '; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}