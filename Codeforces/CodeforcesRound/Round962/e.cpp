#include <bits/stdc++.h>

using namespace std;
const long long mod = 1000000007LL; 
string s; 
int f0[200005];
int f1[200005];     
map <int, long long> sum; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    int n = (int) s.size();
    sum.clear();
    sum[0] = 1;
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      f0[i] = f0[i - 1]; 
      f1[i] = f1[i - 1]; 
      if (s[i - 1] == '0') {
        f0[i]++; 
      }
      else {
        f1[i]++; 
      }
      ans += (long long) (n - i + 1) * sum[f0[i] - f1[i]];
      ans %= mod;                        
      sum[f0[i] - f1[i]] += i + 1;   
    }
    cout << ans << endl; 
  }
  return 0; 
}