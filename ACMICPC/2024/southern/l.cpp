#include <bits/stdc++.h> 

using namespace std;
int a[100005]; 
int n, k;
long long fact[100005], inv_fact[100005];
vector <int> listDivisors[100005];  
const long long mod = 100003LL; 
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
void init() {
  fact[0] = 1LL;
  inv_fact[0] = 1LL;
  for (int i = 1; i <= 100000; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[i] = fastpow(fact[i], mod - 2);  
  }
}
void erathones() {
  for (int i = 1; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) {
      listDivisors[j].push_back(i); 
    }
  }
}
long long f[100005];

int main () {
  erathones(); 
  init(); 
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  int numb = 0; 
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1) {
      numb++; 
      for (int j = 0; j < (int) listDivisors[i].size(); j++) {
        a[listDivisors[i][j]] ^= 1; 
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    f[i] = n - i; 
    (f[i] *= f[i + 1]) %= mod; 
    (f[i] += n) %= mod;
    (f[i] *= fastpow(i, mod - 2)) %+ mod;  
  }
  for (int i = 1; i <= k; i++) {
    f[i] = 1; 
  }
  long long ans = fact[n]; 
  long long total = 0LL; 
  for (int i = 1; i <= numb; i++) {
    (total += f[i]) %= mod; 
  }
  (ans *= total) %= mod; 
  cout << ans; 
  return 0; 
}