#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 55; 
const long long MOD = 998244353LL;
map <long long, long long> dp[MAX_N]; 
int n, k; 
long long C[MAX_N][MAX_N];
long long D[MAX_N];
long long ways[MAX_N];   

long long POW(const long long &x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long tmp = POW(x, n >> 1); 
  (tmp *= tmp) %= MOD; 
  if (n % 2 == 1) {
    (tmp *= x) %= MOD; 
  }
  return tmp; 
}

void init() {
  for (int i = 0; i < MAX_N; i++) {
    C[i][i] = 1;
    C[i][0] = 1; 
  }
  for (int i = 1; i < MAX_N; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; 
    }
  }
  D[0] = 1;
  D[1] = 0;
  for (int i = 2; i < MAX_N; i++) {
    D[i] = (1LL * (i - 1) * ((D[i - 1] + D[i - 2]) % MOD)) % MOD; 
  }
  for (int i = 2; i < MAX_N; i++) {
    ways[i] = D[i];
    for (int j = i - 2; j >= 1; j--) {
      long long mul = ways[j];
      (mul *= D[i - j]) %= MOD;
      (mul *= C[i - 1][j - 1]) %= MOD; 
      ways[i] -= mul;
      (ways[i] += MOD) %= MOD;  
    }  
  }
}

int lcm(int x, int y) {
  return x * y / __gcd(x, y); 
}

int main () {
  init(); 
  cin >> n >> k; 
  dp[0][1] = 1; 
  for (int i = 0; i < n; i++) {
    for (map <long long, long long> :: iterator it = dp[i].begin(); it != dp[i].end(); it++) {
      (dp[i + 1][it->first] += it->second) %= MOD; 
      for (int j = 2; i + j <= n; j++) {
        (dp[i + j][lcm(it->first, j)] += (((1LL * it->second * C[n - i - 1][j - 1]) % MOD) * ways[j]) % MOD) %= MOD; 
      }
    }
  }
  long long ans = 0LL; 
  for (map <long long, long long> :: iterator it = dp[n].begin(); it != dp[n].end(); it++) {
    (ans += (POW(it->first, k) * it->second) % MOD) %= MOD;
  }
  cout << ans; 
  return 0; 
}