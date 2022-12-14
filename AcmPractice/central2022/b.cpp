#include <iostream> 
#include <vector>
#include <string>
#include <math.h> 
std::string s; 
int numQuery; 
int cnt[100005]; 
std::vector <int> z; 

std::vector <int> createZfunction(const std::string &s) {
  int n = (int) s.size(); 
  std::vector <int> ret;
  ret.resize(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) {
      ret[i] = std::min(r - i + 1, ret[i - l]); 
    }
    while (i + ret[i] < n && s[ret[i]] == s[i + ret[i]]) {
      ret[i]++; 
    }
    if (i + ret[i] - 1 > r) {
      l = i;
      r = i + ret[i] - 1; 
    }
  } 
  return ret; 
}

int main () {
  std::cin >> s; 
  int n = (int) s.size(); 
  z = createZfunction(s);
  for (int i = 1; i < n; i++) {
    cnt[z[i]]++; 
  }
  for (int i = n - 1; i >= 1; i--) {
    cnt[i] += cnt[i + 1];
  }
  std::cin >> numQuery;
  for (int query = 1; query <= numQuery; query++) {
    int len;
    std::cin >> len; 
    if (cnt[len] <= 1) {
      std::cout << "NO" << std::endl; 
      continue; 
    }
    if (z[n - len] != len) {
      std::cout << "NO" << std::endl;
      continue; 
    }
    std::cout << "YES " << cnt[len] + 1 << std::endl; 
  }
  return 0; 
}