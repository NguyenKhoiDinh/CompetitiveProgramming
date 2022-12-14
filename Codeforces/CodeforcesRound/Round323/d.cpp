#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>

using namespace std; 
const int MAX_N = 4005; 
const long long MOD = 1000000007;
long long dp[2][MAX_N][2][2];
string A; 
int p, alpha;
vector <int> a;

vector <int> convert(const string &A) {
  vector <int> digit;
  for (int i = 0; i < (int) A.size(); i++) {
    digit.push_back(A[i] - '0'); 
  }
  vector <int> ans; 
  while (true) {  
    long long remain = 0LL;
    vector <int> after; 
    for (int i = 0; i < (int) digit.size(); i++) {
      remain = remain * 10 + digit[i];
      after.push_back(remain / p);
      remain %= p;  
    }
    ans.push_back(remain);
    reverse(after.begin(), after.end());
    while (after.empty() == false && after.back() == 0) {
      after.pop_back();
    }
    if (after.empty() == true) {
      break;
    }
    reverse(after.begin(), after.end());
    digit = after;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

long long getTotal(long long x) {
  long long ret = x * (x + 1) / 2;
  ret %= MOD;
  return ret;
}

int main () {
  cin >> p >> alpha >> A;
  a = convert(A);         
  int n = (int) a.size();
  if (alpha > n) {
    cout << 0;
    return 0; 
  }
  dp[0][0][0][1] = 1;
  for (int i = 0; i < n; i++) {
    int cur = i & 1; 
    int nxt = !cur;
    memset(dp[nxt], 0, sizeof(dp[nxt]));
    for (int pw = 0; pw <= i; pw++) {
      for (int rem = 0; rem <= 1; rem++) {
        for (int status = 0; status <= 1; status++) {
          if (dp[cur][pw][rem][status] == 0) {
            continue; 
          }
          if (status == 0) {
            if (rem == 0) {
              (dp[nxt][pw][0][0] += (getTotal(p) * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw][1][0] += (getTotal(p - 1) * dp[cur][pw][rem][status]) % MOD) %= MOD;
            }  
            else {
              (dp[nxt][pw + 1][0][0] += (getTotal(p - 1) * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw + 1][1][0] += (getTotal(p) * dp[cur][pw][rem][status]) % MOD) %= MOD;  
            }
          }
          else {
            if (rem == 0) {
              (dp[nxt][pw][0][0] += (getTotal(a[i]) * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw][1][0] += (getTotal(a[i] - 1) * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw][0][1] += (1LL * (a[i] + 1) % MOD * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw][1][1] += (1LL * a[i] * dp[cur][pw][rem][status]) % MOD) %= MOD;
            }
            else {
              (dp[nxt][pw + 1][0][0] += ((getTotal(p - 1) - getTotal(p - a[i] - 1) + MOD) % MOD * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw + 1][1][0] += ((getTotal(p) - getTotal(p - a[i]) + MOD) % MOD * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw + 1][0][1] += (1LL * (p - a[i] - 1) % MOD * dp[cur][pw][rem][status]) % MOD) %= MOD;
              (dp[nxt][pw + 1][1][1] += (1LL * (p - a[i]) % MOD * dp[cur][pw][rem][status]) % MOD) %= MOD;   
            }
          }
        }
      }  
    }   
  }
  long long ans = 0LL;
  for (int pw = alpha; pw <= n; pw++) {
    (ans += dp[n & 1][pw][0][0]) %= MOD;
    (ans += dp[n & 1][pw][0][1]) %= MOD;
  }                           
  cout << ans;
  return 0; 
}