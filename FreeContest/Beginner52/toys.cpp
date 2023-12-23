#include <iostream> 
#include <algorithm> 
#include <utility> 
#include <vector> 
#include <set> 
int n; 
int a[100005]; 
int M; 
std::set <int> myset; 

int main () {
  std::cin >> n >> M;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    myset.insert(a[i]); 
  }
  std::vector <int> ans; 
  int p = 1; 
  while (true) {
    if (myset.find(p) == myset.end()) {
      if (M >= p) {
        M -= p;
        ans.push_back(p);  
      }
      else {
        break; 
      }
    }
    p++; 
  }
  std::cout << (int) ans.size() << std::endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}