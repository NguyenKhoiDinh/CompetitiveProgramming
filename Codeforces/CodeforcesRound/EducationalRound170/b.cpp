#include <bits/stdc++.h>

using namespace std;
const long long mod = 1000000007LL; 
long long fact[200005], inv_fact[200005]; 
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
  for (int i = 1; i <= 200000; i++) {
    fact[i] = fastpow(2LL, i);
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
}
int a[200005], b[200005]; 

int main () {                      
  init(); 
  int n;
  cin >> n; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i]; 
  }
  for (int i = 1; i <= n; i++) {
    cout << fact[b[i]] << endl;  
  }
  return 0; 
}