#include <iostream>
#include <string> 
#include <map>
#include <vector>
#include <algorithm>
const int BLOCK = 320;
struct query {
  int l, r, id;
  bool operator < (const query &other) const {
    if (l / BLOCK != other.l / BLOCK) {
      return l < other.l; 
    }
    return r < other.r; 
  }  
}; 
int n, numQueries;
long long p; 
std::string s; 
std::vector <query> listQuery; 
std::vector <int> ans; 
std::vector <long long> inv10;
std::vector <long long> sum; 
std::vector <int> rem, countRem; 

long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2);
  (ret *= ret) %= p;
  if (n % 2 == 1) {
    (ret *= x) %= p;
  }
  return ret; 
}

void init() {
  sum.resize(n + 2, 0LL);
  inv10.resize(n + 2, 0LL);
  rem.resize(n + 2, 0LL); 
  inv10[0] = 1LL; 
  for (int i = 1; i <= n; i++) {
    sum[i] = (sum[i - 1] * 10LL + s[i - 1] - '0') % p; 
    inv10[i] = (inv10[i - 1] * 10LL) % p; 
  }     
  for (int i = 0; i <= n; i++) {
    inv10[i] = fastpow(inv10[i], p - 2); 
  }
  std::map <int, int> ID; 
  for (int i = 0; i <= n; i++) {
    long long r = sum[i]; 
    (r *= inv10[i]) %= p;
    std::map <int, int>::iterator it = ID.find(r);
    if (it == ID.end()) {
      ID[(int) r] = (int) ID.size(); 
    }
    rem[i] = ID[(int) r]; 
  }
}

int main () {
  std::cin >> p;
  std::cin >> s;
  n = (int) s.size(); 
  std::cin >> numQueries;
  ans.resize(numQueries);  
  for (int i = 1; i <= numQueries; i++) {
    int l, r;
    std::cin >> l >> r; 
    listQuery.push_back((query) {l, r, i - 1}); 
  }
  if (p == 2 || p == 5) {
    std::vector <std::vector <long long> > f;
    std::vector <std::vector <int> > cnt;  
    f.resize(n + 5);
    cnt.resize(n + 5); 
    for (int i = 0; i <= n; i++) {
      f[i].resize(10, 0);
      cnt[i].resize(10, 0);  
    }
    for (int i = 1; i <= n; i++) {
      for (int r = 0; r < 10; r++) {
        f[i][r] = f[i - 1][r];
        cnt[i][r] = cnt[i - 1][r];  
      }
      if ((s[i - 1] - '0') % p == 0) {
        f[i][s[i - 1] - '0'] += i; 
        cnt[i][s[i - 1] - '0']++; 
      }
    }
    for (int i = 0; i < numQueries; i++) {
      int l = listQuery[i].l;
      int r = listQuery[i].r; 
      long long ret = 0LL; 
      for (int rem = 0; rem < 10; rem++) {
        ret += f[r][rem] - f[l - 1][rem];
        ret -= 1LL * (cnt[r][rem] - cnt[l - 1][rem]) * (l - 1);    
      }
      std::cout << ret << std::endl; 
    }   
    return 0; 
  }
  std::sort(listQuery.begin(), listQuery.end());
  for (int i = 0; i < (int) listQuery.size(); i++) {
    listQuery[i].l--;
  }
  init();
  ans.resize(numQueries);
  countRem.resize(n, 0);
  int L = listQuery[0].l;
  int R = listQuery[0].r;
  long long ret = 0LL;
  for (int i = L; i <= R; i++) {
    ret += countRem[rem[i]];
    countRem[rem[i]]++; 
  }    
  ans[listQuery[0].id] = ret; 
  for (int i = 1; i < (int) listQuery.size(); i++) {
    while (L < listQuery[i].l) {
      countRem[rem[L]]--;
      ret -= countRem[rem[L]];
      L++; 
    }
    while (L > listQuery[i].l) {
      L--;
      ret += countRem[rem[L]];
      countRem[rem[L]]++; 
    }
    while (R < listQuery[i].r) {
      R++; 
      ret += countRem[rem[R]];
      countRem[rem[R]]++;
    }
    while (R > listQuery[i].r) {
      countRem[rem[R]]--;
      ret -= countRem[rem[R]];
      R--;
    }
    ans[listQuery[i].id] = ret; 
  }
  for (int i = 0; i < numQueries; i++) {
    std::cout << ans[i] << std::endl;
  }
  return 0;                              
}