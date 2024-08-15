#include <iostream> 
#include <deque> 
#include <algorithm> 
#include <utility>
#include <map> 
#include <vector> 
int n, m; 
std::vector <std::pair <int, int> > a, b; 
std::map <int, int> id; 
std::vector <int> v; 
int fw[400005]; 
void update(int index, const int &value) {
  for (; index <= 400000; index += index & -index) {
    fw[index] += value; 
  }
}
int get(int index) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int main () {
  std::cin >> n >> m;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first >> a[i].second; 
    v.push_back(a[i].first);
    v.push_back(a[i].second); 
  }
  b.resize(m); 
  for (int i = 0; i < m; i++) {
    std::cin >> b[i].first >> b[i].second; 
    v.push_back(b[i].first);
    v.push_back(b[i].second); 
  }
  std::sort(v.begin(), v.end()); 
  int sz = 0; 
  for (int i = 0; i < (int) v.size(); i++) {
    if (id.find(v[i]) == id.end()) {
      sz++; 
      id[v[i]] = sz; 
    }  
  }
  for (int i = 0; i < n; i++) {
    a[i].first = id[a[i].first];
    a[i].second = id[a[i].second]; 
  }
  for (int i = 0; i < m; i++) {
    b[i].first = id[b[i].first]; 
    b[i].second = id[b[i].second]; 
  }
  std::sort(a.begin(), a.end()); 
  std::sort(b.begin(), b.end());
  std::vector <std::pair <int, int> > tmp;
  for (int i = 0; i < m; i++) {
    if (tmp.empty() == false && tmp.back().second >= b[i].second) {
      continue; 
    }
    tmp.push_back(b[i]); 
  }
  int ans = 0;  
  int p = n - 1;
  for (int i = (int) tmp.size() - 1; i >= 0; i--) {
    while (p >= 0 && a[p].first >= tmp[i].first) {
      update(a[p].second, 1); 
      p--; 
    }
    int numb = get(tmp[i].second) - get(tmp[i].first - 1);
    ans = std::max(ans, numb);    
  }
  std::cout << ans;
  return 0; 
}