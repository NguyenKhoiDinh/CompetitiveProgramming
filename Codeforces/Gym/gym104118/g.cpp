#include <iostream> 
#include <vector> 
#include <utility>
#include <algorithm>
#include <math.h>
#include <map> 
int n, mod;
std::vector <int> listMod; 
std::vector <std::pair <int, int> > v; 
std::map <int, int> id; 
int f[1000005]; 

int main () {
  std::cin >> n >> mod; 
  for (int i = 1; i <= n; i++) {
    int L, R;
    std::cin >> L >> R; 
    if (R - L + 1 >= mod) {
      listMod.push_back(0);
      listMod.push_back(mod);   
      v.push_back(std::make_pair(0, mod));
      continue;  
    }
    int rL = L % mod; 
    int rR = R % mod; 
    if (rL <= rR) {
      listMod.push_back(rL);
      listMod.push_back(rR + 1); 
      v.push_back(std::make_pair(rL, rR + 1)); 
    }
    else {
      listMod.push_back(rL); 
      listMod.push_back(mod); 
      v.push_back(std::make_pair(rL, mod)); 
      listMod.push_back(0);
      listMod.push_back(rR + 1); 
      v.push_back(std::make_pair(0, rR + 1)); 
    }
  }
  std::sort(listMod.begin(), listMod.end());
  for (int i = 0; i < (int) listMod.size(); i++) {
    int sz = (int) id.size(); 
    if (id.find(listMod[i]) == id.end()) {
      id[listMod[i]] = sz + 1; 
    }
  }
  for (int i = 0; i < (int) v.size(); i++) {
    int vl = id[v[i].first]; 
    int vr = id[v[i].second]; 
    f[vl]++;
    f[vr]--; 
  } 
  for (int i = 1; i <= 1000000; i++) {
    f[i] += f[i - 1]; 
  }
  int ans = 0; 
  for (int i = 1; i <= 1000000; i++) {
    ans = std::max(ans, f[i]); 
  }
  std::cout << ans; 
  return 0; 
}