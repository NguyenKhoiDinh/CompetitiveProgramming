#include <iostream> 
#include <string>
#include <cstring>
const long long mod = 1000000007; 
int numTest; 
std::string s; 
int n; 
long long fact[405], invFact[405]; 
long long dp[405][405][405]; 

long long power(const long long x, long long n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = power(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

void init() {
  fact[0] = 1LL; 
  invFact[0] = 1LL; 
  for (int i = 1; i <= 400; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod; 
    invFact[i] = power(fact[i], mod - 2); 
  }
}

int main () {
  init(); 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n;
    std::cin >> s;
    std::memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        dp[i][j][1] = j - i + 1;
        dp[i][j][0] = 1;  
      }
      dp[i + 1][i][0] = 1; 
    } 
    for (int j = 2; j <= n; j++) {
      for (int i = j - 1; i >= 1; i--) {
        for (int len = 2; len <= j - i + 1; len++) {
          if (s[i - 1] == s[j - 1]) {
            (dp[i][j][len] += dp[i + 1][j - 1][len - 2]) %= mod; 
          }    
          (dp[i][j][len] += dp[i + 1][j][len]) %= mod; 
          (dp[i][j][len] += dp[i][j - 1][len]) %= mod;
          dp[i][j][len] -= dp[i + 1][j - 1][len]; 
          (dp[i][j][len] += mod) %= mod;
        }
      }
    }
    long long ans = 0LL; 
    for (int len = 0; len < n; len++) {
      long long mul = dp[1][n][len]; 
      (mul *= fact[len]) %= mod; 
      (mul *= fact[n - len]) %= mod;
      (ans += mul) %= mod;  
    }
    (ans *= invFact[n]) %= mod; 
    std::cout << ans << std::endl; 
  }
  return 0; 
}      
