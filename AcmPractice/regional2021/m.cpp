#include <bits/stdc++.h> 

using namespace std;
const long long mod = 1000000007; 
long long dp1[1000007]; 
long long dp[1000007]; 
string N;

int main () {
  cin >> N; 
  int len = (int) N.size(); 
  dp1[0] = 0; 
  for (int i = 1; i <= len; i++) {
    dp1[i] = ((dp1[i - 1] * 10LL) % mod + ((N[i - 1] - '0') * i) % mod) % mod;  
  }
  dp[0] = 0; 
  for (int i = 1; i <= len; i++) {
    dp[i] = (dp[i - 1] * 100) % mod;
    (dp[i] += (dp1[i - 1] * (N[i - 1] - '0') * 20) % mod) %= mod; 
    (dp[i] += (N[i - 1] - '0') * (N[i - 1] - '0') * i % mod) %= mod; 
  }
  long long ans = 0LL; 
  for (int i = 1; i <= len; i++) {
    (ans += dp[i]) %= mod; 
  }
  cout << ans;
  return 0; 
}