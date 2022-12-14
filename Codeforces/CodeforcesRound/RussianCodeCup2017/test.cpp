#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const LL mod = 998244353;
int _min(int x, int y) {return x < y ? x : y;}
int _max(int x, int y) {return x > y ? x : y;}
int read() {
  int s = 0, f = 1; char ch = getchar();
  while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
  while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}

int a[2100], b[2100], o[2100];
LL f0[2][2010][11], f1[2][2010][11];
LL jc[2100], inv[2100];

LL pow_mod(LL a, LL k) {
  LL ans = 1;
  while(k) {
    if(k & 1) (ans *= a) %= mod;
    (a *= a) %= mod; k /= 2;
  } return ans;
}

LL C(int n, int m) {return jc[n] * inv[n - m] % mod * inv[m] % mod;}
LL calc(int n, int m) {
  if(n == 0) {
    if(m) return 0;
    else return 1;
  } return jc[m] * C(n + m - 1, m) % mod;
}

int main() {
  freopen("input.txt", "r", stdin); 
  freopen("output2.txt", "w", stdout);
  int tt = read();
  jc[0] = inv[0] = 1;
  for(int i = 1; i <= 2000; i++) jc[i] = jc[i - 1] * i % mod, inv[i] = pow_mod(jc[i], mod - 2);
  while(tt--) {
    int n = read(), n1 = 0, n2 = 0;
    for(int i = 1; i <= n; i++) {
      int x = read(), now = x, len = 0;
      while(now) now /= 10, ++len;
      if(len & 1) a[++n1] = x % 11;
      else b[++n2] = x % 11;
    }
    memset(f0[0], 0, sizeof(f0[0]));
    memset(f1[0], 0, sizeof(f1[0]));
    f0[0][0][0] = f1[0][0][0] = 1; int now0 = 0;
    for(int i = 1; i <= n1; i++) {
      now0 ^= 1; memset(f0[now0], 0, sizeof(f0[now0]));
      for(int j = 0; j <= i; j++) {
        for(int k = 0; k < 11; k++) {
          f0[now0][j][k] += f0[now0 ^ 1][j][(k - a[i] + 11) % 11];
          if(j) (f0[now0][j][k] += f0[now0 ^ 1][j - 1][(k + a[i]) % 11]) %= mod;
        }
      }
    } int now1 = 0;
    for(int i = 1; i <= n2; i++) {
      now1 ^= 1; memset(f1[now1], 0, sizeof(f1[now1]));
      for(int j = 0; j <= i; j++) {
        for(int k = 0; k < 11; k++) {
          f1[now1][j][k] += f1[now1 ^ 1][j][(k - b[i] + 11) % 11];
          if(j) (f1[now1][j][k] += f1[now1 ^ 1][j - 1][(k + b[i]) % 11]) %= mod;
        }
      }
    } LL ans = 0;
    for(int k = 0; k < 11; k++) {
      LL h1 = f0[now0][n1 / 2][k] * jc[n1 / 2] % mod * jc[n1 - n1 / 2] % mod;
      for(int i = 0; i <= n2; i++) {
        LL h2 = f1[now1][i][(11 - k) % 11] * calc(n1 + 1 - (n1 + 1) / 2, n2 - i) % mod * calc((n1 + 1) / 2, i) % mod;
        (ans += h1 * h2 % mod) %= mod;
      }
    } printf("%lld\n", ans);
  }
  return 0;
}