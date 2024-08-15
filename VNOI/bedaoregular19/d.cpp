#include <iostream>
#include <set>
#include <map> 
#include <vector>
#include <algorithm>
const int BLOCK = 450; 
int n, numQueries;
std::vector <long long> a, b;
std::map <long long, int> mapValue;
struct segment {
  int l, r, id; 
  bool operator < (const segment &other) const {
    if (l / BLOCK != other.l / BLOCK) {
      return (l / BLOCK < other.l / BLOCK); 
    }  
    return r < other.r; 
  }
};  
std::vector <segment> lista, listb; 
std::vector <long long> valuea, valueb; 
int cnt[400005]; 
long long pw[400005]; 
void solve(const std::vector <long long> &a, const std::vector <segment> &lista, std::vector <long long> &valuea) {
  for (int i = 1; i <= 400000; i++) {
    cnt[i] = 0; 
  }
  int n = (int) lista.size(); 
  valuea.resize(n);
  long long value = 0LL; 
  int L = lista[0].l;
  int R = lista[0].r; 
  for (int i = L; i <= R; i++) {
    cnt[a[i]]++; 
    if (cnt[a[i]] == 1) {
      value += a[i] * pw[a[i]];   
    }
  }
  valuea[lista[0].id] = value; 
  for (int i = 1; i < n; i++) {
    while (L > lista[i].l) {
      L--; 
      cnt[a[L]]++; 
      if (cnt[a[L]] == 1) {
        value += a[L] * pw[a[L]]; 
      }
    }
    while (L < lista[i].l) {
      cnt[a[L]]--; 
      if (cnt[a[L]] == 0) {
        value -= a[L] * pw[a[L]];
      }
      L++; 
    }
    while (R < lista[i].r) {
      R++; 
      cnt[a[R]]++; 
      if (cnt[a[R]] == 1) {
        value += a[R] * pw[a[R]]; 
      }
    }
    while (R > lista[i].r) {
      cnt[a[R]]--;
      if (cnt[a[R]] == 0) {
        value -= a[R] * pw[a[R]]; 
      }
      R--; 
    }
    valuea[lista[i].id] = value; 
  }
}

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  pw[0] = 1LL; 
  for (int i = 1; i <= 400000; i++) {
    pw[i] = pw[i - 1] * 1000000009LL; 
  }
  std::cin >> n >> numQueries; 
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (mapValue.find(a[i]) == mapValue.end()) {
      mapValue[a[i]] = (int) mapValue.size() + 1; 
    }
    a[i] = mapValue[a[i]]; 
  }
  b.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> b[i]; 
    if (mapValue.find(b[i]) == mapValue.end()) {
      mapValue[b[i]] = (int) mapValue.size() + 1; 
    }
    b[i] = mapValue[b[i]]; 
  }
  for (int query = 0; query < numQueries; query++) {
    int la, ra, lb, rb;
    std::cin >> la >> ra >> lb >> rb;
    la--;
    ra--;
    lb--;
    rb--; 
    lista.push_back((segment) {la, ra, query});
    listb.push_back((segment) {lb, rb, query}); 
  }  
  std::sort(lista.begin(), lista.end());
  solve(a, lista, valuea); 
  std::sort(listb.begin(), listb.end()); 
  solve(b, listb, valueb);
  for (int query = 0; query < numQueries; query++) {
    std::cout << (valuea[query] == valueb[query] ? "YES" : "NO") << std::endl;
  } 
  return 0; 
}