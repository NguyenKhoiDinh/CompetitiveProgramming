#include <bits/stdc++.h> 

using namespace std; 
const long long mod = 1000000007; 
long long fact[105]; 
long long C[105][105]; 

class SkyscraperCounting {
  public: 
  int count(string s) {
    int n = (int) s.size();
    for (int i = 0; i <= n; i++) {
      C[i][i] = 1; 
      C[i][0] = 1; 
    } 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod; 
      }
    }
    fact[0] = 1LL; 
    for (int i = 1; i <= n; i++) {
      fact[i] = (fact[i - 1] * i) % mod; 
    }
    vector <int> pos; 
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'O') {
        pos.push_back(i);   
      }
    }
    reverse(pos.begin(), pos.end()); 
    if (pos[0] != 0) {
      return 0LL; 
    }
    long long ans = 0LL;
    (ans *= fact[n - pos.back()]) %= mod;  
  }
};

SkyscraperCounting S; 

int main () {
  return 0; 
}