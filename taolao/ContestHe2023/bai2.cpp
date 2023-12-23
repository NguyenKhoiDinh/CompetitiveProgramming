#include <iostream>
#include <map> 
#include <algorithm> 
#include <vector> 
struct gift {
  int value; 
  long long luckyNumber; 
  bool operator < (const gift &other) const {
    return luckyNumber < other.luckyNumber; 
  }
};
struct question {
  long long l, r; 
};
int n, m; 
std::vector <gift> a; 
std::vector <question> listQueries; 
std::map <long long, int> ID; 
std::vector <long long> tmp; 
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
    tmp.push_back(listQueries[query].l);
    tmp.push_back(listQueries[query].r);    
  }
  std::sort(tmp.begin(), tmp.end());
  for (int i = 0; i < (int) tmp.size(); i++) {
    ID[tmp[i]] = (int) ID.size() + 1; 
  }
  for (int i = 0; i < n; i++) {
    int position = ID[a[i].luckyNumber]; 
    sum[position] += a[i].value; 
  } 
  for (int i = 1; i <= 300000; i++) {
    sum[i] += sum[i - 1];   
  }
  for (int i = 0; i < (int) listQueries.size(); i++) {
    int l = listQueries[i].l; 
    int r = listQueries[i].r;
    l = ID[l];
    r = ID[r];
    if (l > r) {
      std::swap(l, r); 
    } 
    std::cout << sum[r] - sum[l - 1] << ' '; 
  }
  return 0; 
}