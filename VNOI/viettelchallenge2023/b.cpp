#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
int numTest; 
int c, n, m; 
std::vector <std::pair <int, int> > pos; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> c >> n >> m;
    pos.clear(); 
    for (int i = 1; i <= n; i++) {
      int position;
      std::cin >> position;
      pos.push_back(std::make_pair(position, -1));   
    }
    for (int i = 1; i <= m; i++) {
      int position, need; 
      std::cin >> position >> need;
      pos.push_back(std::make_pair(position, need)); 
    }
    std::sort(pos.begin(), pos.end());
    int capacity = c; 
    long long ans = 0LL; 
    for (int i = 0; i < (int) pos.size(); i++) {
      if (pos[i].second == -1) {
        capacity = c; 
      }
      else {
        if (pos[i].second <= capacity) {
          ans += pos[i].second; 
          capacity -= pos[i].second; 
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}