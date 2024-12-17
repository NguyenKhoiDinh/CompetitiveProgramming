#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
long long f[64][2];   
long long sum[100005]; 
int numQueries, phi; 
long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}
long long calc(long long n) {
  memset(f, 0, sizeof(f));
  int pos; 
  for (int bit = 0; bit <= 63; bit++) {
    if ((n & (1LL << ((long long) bit))) > 0) {
      pos = bit; 
    }
  }
  f[pos][0] = 1; 
  f[pos][1] = 2;
  for (int i = pos; i > 0; i--) {
    for (int state = 0; state <= 1; state++) {
      if (f[i][state] == 0) {
        continue; 
      }
      int nextBit = ((n & (1LL << ((long long) (i - 1)))) > 0);
      for (int b = 0; b <= 1; b++) {
        if (state == 0) {
          (f[i - 1][0] += (f[i][state] * (1 << b)) % mod) %= mod; 
        }
        else if (b <= nextBit) {
          (f[i - 1][b == nextBit] += (f[i][state] * (1 << b)) % mod) %= mod; 
        }
      }
    } 
  }
  long long ret = f[0][0];  
  return ret; 
}

int main () {
  long long inv2 = fastpow(2, mod - 2); 
  cin >> numQueries >> phi; 
  for (int query = 1; query <= numQueries; query++) {
    long long l, r; 
    cin >> l >> r; 
    long long ans = calc(r + 1);
    ans -= calc(l);   
    if (ans < 0) {
      ans += mod; 
    } 
    if (phi == 1) {
      cout << ans << endl; 
    }
    else {
      long long sumr = r % mod; 
      (sumr *= (r + 1) % mod) %= mod; 
      (sumr *= inv2) %= mod;
      long long suml = l % mod;
      (suml *= (l - 1) % mod) %= mod;
      (suml *= inv2) %= mod;
      long long ret = sumr - suml;
      if (ret < 0) {
        ret += mod; 
      }
      (ret += (r - l + 1)) %= mod;  
      ret -= ans; 
      if (ret < 0) {
        ret += mod;
      }
      cout << ret << endl; 
    }
  }
  return 0; 
}