#include <bits/stdc++.h> 

using namespace std; 
const long long mod = 998244353LL; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    long long w, g, l; 
    cin >> w >> g >> l; 
    long long ans = (2LL * l) + 1;
    ans %= mod;
    w -= g; 
    w %= mod;
    (ans *= w) %= mod;
    cout << ans << endl; 
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}