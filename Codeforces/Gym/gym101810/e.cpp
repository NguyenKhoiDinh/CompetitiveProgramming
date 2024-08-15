#include <iostream>
const long long mod = 1000000007LL; 
int n; 
int numTest; 
int a[100005]; 
long long prefix[100005], suffix[100005]; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    prefix[0] = 1LL; 
    for (int i = 1; i <= n; i++) {
      prefix[i] = (prefix[i - 1] * a[i]) % mod; 
    }
    suffix[n + 1] = 1LL;
    for (int i = n; i >= 1; i--) {
      suffix[i] = (suffix[i + 1] * a[i]) % mod; 
    }
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      long long mul = a[i] - 1;
      (mul *= prefix[i - 1]) %= mod;
      (mul *= suffix[i + 1]) %= mod;
      (ans += mul) %= mod;  
    }                      
    std::cout << ans << std::endl;
  }
  return 0; 
}