#include <iostream> 
#include <string>
const long long mod = 1000000007; 
int numTest; 
long long f[500005]; 

void init() {
  f[0] = 0; 
  for (int i = 1; i <= 500000; i++) {
    f[i] = (f[i - 1] + 1LL * i * (i + 1) / 2) % mod; 
  }
}

int main () {
  init();
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s;
    std::cin >> s; 
    int n = (int) s.size(); 
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      long long number = ((f[n] - f[i - 1] + mod) % mod - f[n - i] + mod) % mod; 
      (ans += (1LL * (s[i - 1] - 'a' + 1) * number) % mod) %= mod;  
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}