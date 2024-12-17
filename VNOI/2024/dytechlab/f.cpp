#include <bits/stdc++.h> 

using namespace std;
const long long mod = 998244353LL;
int n;
int h[1000005]; 
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
pair <long long, int> calc(int l, int r) {
  if (l == r) {
    return make_pair(1LL, -1); 
  }
  if (l > r) {
    return make_pair(1LL, -1); 
  }
  int p = -1;
  for (int i = r - 1; i >= l; i--) {
    if (h[i] > h[i + 1]) {
      p = i;
      break; 
    }
  }  
  int maxHeight = h[l];
  int pos = l; 
  for (int i = l; i <= r; i++) {
    if (maxHeight < h[i]) {
      maxHeight = h[i];
      pos = i;       
    }  
  } 
  pair <long long, int> left = calc(l, pos - 1); 
  pair <long long, int> right = calc(pos + 1, r);
  long long ways = 1LL;
  (ways *= right.first) %= mod;
  if (right.second == -1) {
    (ways *= left.first) %= mod; 
  }
  else {
    if (r > pos) {
      (ways *= r - pos) %= mod; 
    }
    (ways *= left.first) %= mod; 
  }
  return make_pair(ways, p);     
} 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i]; 
  }
  cout << calc(1, n).first; 
  return 0; 
}