#include <bits/stdc++.h> 

using namespace std; 
const long long mod = 998244353LL; 
string s; 
long long k; 
long long f[100005], ways[100005]; 
bool ok[65]; 

int main () {
  for (int i = 10; i <= 26; i++) {
    int d = i / 10; 
    int r = i % 10;             
    ok[r * 10 + d] = true; 
  }
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> s >> k;
    int n = (int) s.size();  
    string st = s; 
    for (int i = 0; i < n; i++) {
      if (st[i] == '?') {
        st[i] = '1'; 
      }
    }
    memset(f, 0LL, sizeof(f));
    memset(ways, 0LL, sizeof(ways));
    reverse(s.begin(), s.end());  
    reverse(st.begin(), st.end());  
    f[0] = 1LL; 
    for (int i = 0; i < n; i++) {
      if (f[i] == 0) {
        continue; 
      }
      if (st[i] != '0') {
        (f[i + 1] += f[i]) %= mod; 
      }
      if (i + 2 <= n && ok[10 * (st[i] - '0') + st[i + 1] - '0'] == true) {
        (f[i + 2] += f[i]) %= mod; 
      }
    }                  
    ways[0] = 1LL; 
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        ways[i + 1] += 2LL * ways[i]; 
        ways[i + 1] = min(ways[i + 1], 2LL * (k + 1)); 
      }
      else {
        ways[i + 1] += ways[i];              
        ways[i + 1] = min(ways[i + 1], 2LL * (k + 1)); 
      }
    }
    string ans = ""; 
    int i = n; 
    while (i > 0) {
      if (s[i - 1] == '?') {
        if (ways[i - 1] < k) {
          if (2LL * ways[i - 1] > k) {
            ans += '1'; 
          } 
          else {
            ans += '2'; 
          }
        }
        else {
          ans += '1'; 
        }  
      }
      else {
        ans += s[i - 1]; 
      }
      i--; 
    }
    cout << ans << ' '; 
    cout << f[n] << endl; 
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}