#include <iostream> 
#include <vector> 
#include <utility>
#include <set> 
int n, m;
std::vector <std::vector <int> > a; 
std::vector <std::pair <int, int> > position[100005]; 
std::vector <std::set <int> > myset;  

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> n >> m;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    a[i].resize(m, 0); 
  }
  myset.resize(n); 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j]; 
      position[a[i][j]].push_back(std::make_pair(i, j)); 
    }  
  }
  long long ans = 0LL; 
  for (int i = 100000; i >= 1; i--) {
    for (int j = 0; j < (int) position[i].size(); j++) {
      std::pair <int, int> cell = position[i][j]; 
      int x = cell.first;
      int y = cell.second; 
      int minRight = m;
      int maxLeft = -1; 
      std::set <int>::iterator it = myset[x].upper_bound(y);
      if (it != myset[x].end()) {
        ans++; 
        minRight = *it; 
      }
      if (it != myset[x].begin()) {
        it--; 
        ans++; 
        maxLeft = *it; 
      }
      int limLeft = maxLeft;
      int limRight = minRight;
      for (int r = x - 1; r >= 0; r--) {
        it = myset[r].upper_bound(y); 
        if (it != myset[r].begin()) {
          it--; 
          if (*it > limLeft) {
            ans++; 
            limLeft = *it; 
          }
        }
      }
      for (int r = x + 1; r < n; r++) {
        it = myset[r].lower_bound(y); 
        if (it != myset[r].end() && *it < limRight) {
          ans++; 
          limRight = *it; 
        }
      }
      myset[x].insert(y);
      ans++;                            
    }
  }
  std::cout << ans; 
  return 0;
}