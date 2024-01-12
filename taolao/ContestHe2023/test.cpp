#include <iostream>
#include <map> 
#include <algorithm> 
#include <vector> 
struct gift {
  int value; 
  int luckyNumber; 
  bool operator < (const gift &other) const {
    return luckyNumber < other.luckyNumber; 
  }
};
struct question {
  int l, r; 
};
int n, m; 
std::vector <gift> a; 
std::vector <question> listQueries; 
std::map <int, int> ID; 
std::vector <int> tmp; 
long long sum[300005];  

int main () {
  std::cin >> n >> m; 
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].value >> a[i].luckyNumber;
    tmp.push_back(a[i].luckyNumber);  
  }
  listQueries.resize(m); 
  for (int query = 0; query < m; query++) {
    std::cin >> listQueries[query].l >> listQueries[query].r;
    int ans = 0; 
    for (int i = 0; i < n; i++) {
      if (listQueries[query].l <= a[i].luckyNumber && a[i].luckyNumber <= listQueries[query].r) {
        ans += a[i].value; 
      }
    }
    std::cout << ans << ' '; 
  }
  return 0; 
}