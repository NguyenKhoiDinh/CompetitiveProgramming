#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
const long long mod = 998244353LL;
long long power2[200005];  
int numTest; 
int n, m;
std::string a, b; 

int main () {
  power2[0] = 1LL;
  for (int i = 1; i <= 200000; i++) {
    power2[i] = (power2[i - 1] * 2LL) % mod; 
  }
  std::cin >> n >> m;
  std::cin >> a >> b;
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  std::vector <int> cnt(m, 0);
  for (int i = m - 1; i >= 0; i--) {
    cnt[i] = (i == m - 1 ? b[i] - '0' : cnt[i + 1] + b[i] - '0'); 
  }
  long long ans = 0LL; 
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      (ans += (power2[i] * cnt[i]) % mod) %= mod;   
    }
  }      
  std::cout << ans << std::endl;
  return 0; 
}