#include <iostream>
#include <vector>
#include <string> 
#include <utility> 
int n, m, numQueries; 
std::vector <std::string> a;
std::vector <std::vector <std::pair <int, int> > > v; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); 
  std::cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  v.resize(n);
  for (int i = 0; i < n; i++) {
    int p = 0; 
    for (char ch = 'a'; ch <= 'z'; ch++) {
      int l = -1;
      int r = -1;
      if ((p < m && a[i][p] != ch) || (p == m)) {
        v[i].push_back(std::make_pair(l, r));   
      }  
      else {
        l = p;
        while (p < m && a[i][p] == ch) {
          r = p;
          p++;
        }
        v[i].push_back(std::make_pair(l, r)); 
      }
    }
  } 
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    int id1, id2;
    std::cin >> id1 >> id2;
    id1--;
    id2--;
    int ans = 0; 
    for (int j = 0; j < 26; j++) {
      int l1 = v[id1][j].first;
      int r1 = v[id1][j].second; 
      int l2 = v[id2][j].first;
      int r2 = v[id2][j].second; 
      if (l1 == -1 || r1 == -1 || l2 == -1 || r2 == -1) {
        continue; 
      }
      if (std::min(r1, r2) >= std::max(l1, l2)) {
        ans += std::min(r1, r2) - std::max(l1, l2) + 1; 
      }
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}