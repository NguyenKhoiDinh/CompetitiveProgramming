#include <iostream> 
#include <map> 
#include <string> 
#include <algorithm> 
#include <math.h>
#include <vector>
#include <utility> 

int n; 
std::pair <std::string, int> a[1000005];                           
bool compare(const std::pair <std::string, int> &a, const std::pair <std::string, int> &b) {
  return ((int) a.first.size() > (int) b.first.size()); 
} 
long long pw29[1000005];
int ans[1000005];
std::map <long long, int> numbAdd[1000005];
const long long mod = 67280421310721LL;             
int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;  
  }
  std::sort(a + 1, a + n + 1, compare); 
  pw29[0] = 1LL; 
  for (int i = 1; i <= 1000000; i++) {
    pw29[i] = (pw29[i - 1] * 29LL) % mod; 
  }
  for (int i = 1; i <= n; i++) {
    std::string s = a[i].first;
    std::vector <long long> hashing; 
    int id = a[i].second; 
    int len = (int) s.size();  
    hashing.resize(len + 1, 0LL);
    for (int j = 1; j <= len; j++) {
      hashing[j] = (hashing[j - 1] + (1LL * (s[j - 1] - 'a' + 1) * pw29[len - j]) % mod) % mod; 
    } 
    int cntAdd = 10000005; 
    for (int j = 1; j <= len; j++) {
      long long total = 0LL; 
      long long prefix = (hashing[j] * 29LL) % mod; 
      (total += prefix) %= mod;
      (total += (1LL * (s[j - 1] - 'a' + 1) * pw29[len - j]) % mod) %= mod;
      long long suffix = (hashing[len] - hashing[j] + mod) % mod; 
      (total += suffix) %= mod; 
      if (numbAdd[len + 1].find(total) == numbAdd[len + 1].end()) {
        cntAdd = 1; 
      }
      else {
        cntAdd = std::min(cntAdd, numbAdd[len + 1][total] + 1); 
      }
    }
    numbAdd[len][hashing[len]] = cntAdd; 
    ans[id] = cntAdd; 
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << std::endl; 
  }                                 
  return 0; 
}