#include <bits/stdc++.h> 

using namespace std;
const long long mod = 1000000007; 
int n, k; 

int main () {
  cin >> n >> k; 
  long long ans = 1LL; 
  for (int i = 2; i <= k; i++) {                   
    (ans *= 2) %= mod;  
  }
  (ans *= (n - k + 1)) %= mod;
  cout << ans;
  return 0; 
}