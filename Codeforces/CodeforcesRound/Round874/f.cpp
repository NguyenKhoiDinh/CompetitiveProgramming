#include <iostream>
#include <map>
#include <vector>
#include <algorithm>  
#include <utility>
int numTest; 
const long long mod = 1000000007LL; 
int n, m; 
int a[200005]; 
long long prefix[200005]; 
std::map <int, int> cnt; 
std::vector <std::pair <int, int> > save; 

long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    cnt.clear(); 
    save.clear(); 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      cnt[a[i]]++; 
    }
    for (std::map <int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      save.push_back(std::make_pair(it->first, it->second)); 
    }
    prefix[0] = 1LL; 
    for (int i = 1; i <= (int) save.size(); i++) {
      prefix[i] = (prefix[i - 1] * save[i - 1].second) % mod; 
    }
    long long ans = 0LL; 
    for (int i = m; i <= (int) save.size(); i++) {
      int r = i - 1; 
      int l = r - m + 1;
      if (save[r].first - save[l].first == m - 1) {
        long long total = prefix[r + 1];
        (total *= fastpow(prefix[l], mod - 2)) %= mod;
        (ans += total) %= mod;    
      } 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}