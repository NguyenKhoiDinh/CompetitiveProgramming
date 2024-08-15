#include <bits/stdc++.h>

using namespace std; 
const int mod = 998244353; 
const int lim = 55002; 
const int inf = 1000000007;
vector <int> fibo; 
int fMin[26][lim + 2][2]; 
long long f[2][lim + 2][11]; 
int n, m, x;

int main () {
  cin >> n >> x >> m;
  fibo.push_back(0); 
  fibo.push_back(1);
  fibo.push_back(1);   
  while (true) {
    int sz = (int) fibo.size(); 
    int value = fibo[sz - 1] + fibo[sz - 2]; 
    if (value <= lim) {
      fibo.push_back(value);   
    }
    else {
      break; 
    }
  }
  int sz = (int) fibo.size();
  sz--;
  for (int i = 0; i <= sz; i++) {
    for (int sum = 0; sum <= lim; sum++) {
      for (int state = 0; state <= 1; state++) {
        fMin[i][sum][state] = inf; 
      }
    }  
  } 
  fMin[0][0][0] = 0; 
  for (int i = 0; i < sz; i++) {
    for (int sum = 0; sum <= lim; sum++) {
      for (int state = 0; state <= 1; state++) {
        if (fMin[i][sum][state] == inf) {
          continue; 
        }
        fMin[i + 1][sum][0] = min(fMin[i + 1][sum][0], fMin[i][sum][state]); 
        if (state == 0) {
          fMin[i + 1][sum + fibo[i + 1]][1] = min(fMin[i + 1][sum + fibo[i + 1]][1], fMin[i][sum][state] + 1);   
        }
      }
    }
  }
  f[0][0][0] = 1;
  for (int i = 0; i <= n; i++) {
    int cur = i % 2;   
    for (int sum = 0; sum <= lim; sum++) {
      for (int p = 0; p < x; p++) {
        if (f[cur][sum][p] == 0) {
          continue; 
        }
        (f[cur][sum][p + 1] += f[cur][sum][p]) %= mod; 
      }
    }
    if (i < n) {
      int nxt = !cur; 
      memset(f[nxt], 0, sizeof(f[nxt])); 
      for (int sum = 0; sum <= lim; sum++) {
        for (int p = 1; p <= x; p++) {
          if (f[cur][sum][p] == 0) {
            continue; 
          }                    
          (f[nxt][sum + fibo[p]][p] += f[cur][sum][p]) %= mod;   
        }
      }
    }                                              
  }                
  int ans = 0;                                     
  for (int sum = 0; sum <= lim; sum++) {
    int numbFibo = min(fMin[sz][sum][0], fMin[sz][sum][1]);
    if (numbFibo == m) {
      (ans += f[n % 2][sum][x]) %= mod;
    }   
  }
  cout << ans;
  return 0;   
}                   