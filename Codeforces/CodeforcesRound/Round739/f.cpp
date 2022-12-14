#include <bits/stdc++.h> 
 
using namespace std;
const int MAX_N = 20; 
 
long long dp[MAX_N][(1 << 10) + 3][3]; 
map <long long, long long> save;
long long n;
int k; 
 
string convert(long long N) {
  string res = "";
  while (N > 0) {
    int r = N % 10;
    N /= 10;
    res += (char) (r + '0');  
  }
  reverse(res.begin(), res.end());
  return res;
}   
 
long long dynamicProgramming(long long n) {
  if (save.find(n) != save.end()) {
    return save[n];
  }
  memset(dp, 0, sizeof(dp));
  string N = convert(n);
  int len = (int) N.size();
  for (int d = 1; d <= 9; d++) {
    int status = 0;
    if (d == N[0] - '0') {
      status = 1;
    }
    else if (d > N[0] - '0') {
      status = 2;
    }
    dp[1][1 << d][status]++; 
  }                  
  for (int i = 1; i < len; i++) {
    for (int mask = 1; mask < (1 << 10); mask++) {
      if ((int) __builtin_popcount(mask) > k) {
        continue;
      }
      for (int status = 0; status <= 2; status++) {
        if (dp[i][mask][status] == 0) {
          continue; 
        }
        long long curValue = dp[i][mask][status];
        for (int d = 0; d <= 9; d++) {
          if ((int) __builtin_popcount(mask | (1 << d)) > k) {
            continue;
          }
          int nextStatus = status;
          if (status == 1) {
            if (d < N[i] - '0') {
              nextStatus = 0;
            }
            else if (d > N[i] - '0') {
              nextStatus = 2; 
            }
          }
          dp[i + 1][mask | (1 << d)][nextStatus] += dp[i][mask][status];
        }
      }
    }
  }
  long long ans = 0LL; 
  for (int i = 1; i <= len; i++) {
    for (int mask = 1; mask < (1 << 10); mask++) {
      int cnt = (int) __builtin_popcount(mask);
      if (cnt != k) {
        continue;  
      }
      for (int status = 0; status <= (i < len ? 2 : 1); status++) {
        ans += dp[i][mask][status];
      }
    }
  }
  save[n] = ans;
  return ans; 
}
 
int main () {
  int test;
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> k;
    long long low = dynamicProgramming(n - 1);
    long long ans = -1;
    long long lo = n;
    long long hi = 9876543210LL;
    while (lo <= hi) {
      long long mid = (lo + hi) >> 1;
      long long cur = dynamicProgramming(mid); 
      if (cur - low > 0) {
        ans = mid;
        hi = mid - 1;
      }
      else {
        lo = mid + 1;
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}