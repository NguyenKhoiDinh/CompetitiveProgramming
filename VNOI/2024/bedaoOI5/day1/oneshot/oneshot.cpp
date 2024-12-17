#include <bits/stdc++.h> 

using namespace std;
const long long mod = 1000000007LL;
int a[100005], l[100005], r[100005];
int n;  
long long prob[100005];
bool check[100005]; 
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

int main () {
  freopen("oneshot.inp", "r", stdin);
  freopen("oneshot.out", "w", stdout); 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    prob[i] = 1LL; 
  }
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    if (l[i] == r[i]) {
      check[l[i]] = true;   
    }
    else if (l[i] < r[i]) {
      int numb = r[i] - l[i] + 1; 
      (prob[l[i]] *= numb - 1) %= mod;
      (prob[l[i]] *= fastpow(numb, mod - 2)) %= mod;
      (prob[r[i] + 1] *= numb) %= mod;
      (prob[r[i] + 1] *= fastpow(numb - 1, mod - 2)) %= mod;   
    }
    else {
      int numb = n - l[i] + 1 + r[i];
      (prob[l[i]] *= numb - 1) %= mod;
      (prob[l[i]] *= fastpow(numb, mod - 2)) %= mod;
      (prob[1] *= numb - 1) %= mod;
      (prob[1] *= fastpow(numb, mod - 2)) %= mod;
      (prob[r[i] + 1] *= numb) %= mod;
      (prob[r[i] + 1] *= fastpow(numb - 1, mod - 2)) %= mod;   
    }
  }
  long long mulProb = 1LL;
  long long ans = 0LL; 
  for (int i = 1; i <= n; i++) {
    if (check[i] == true) {
      ans += a[i];
      continue; 
    }         
    (mulProb *= prob[i]) %= mod; 
    ans -= (a[i] * mulProb) % mod;
    if (ans < 0) {
      ans += mod; 
    }
    (ans += (a[i] * (mod + 1 - mulProb)) % mod) %= mod;  
  }   
  cout << ans; 
  return 0; 
}