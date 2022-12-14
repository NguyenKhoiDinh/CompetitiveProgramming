#include <bits/stdc++.h> 

using namespace std;
string s; 
int query; 
long long f[500005]; 

int main () {
  cin >> s;
  int n = (int) s.size(); 
  cin >> query; 
  for (int i = 1; i <= query; i++) {
    int numb, l, r;
    cin >> numb >> l >> r; 
    f[l] += numb;
    f[r + 1] -= numb; 
  }
  for (int i = 1; i <= n; i++) {
    (f[i] += f[i - 1] + 26 * 200005) %= 26; 
  }                      
  for (int i = 1; i <= n; i++) {
    cout << (char) ((s[i - 1] - 'A' + f[i]) % 26 + 'A'); 
  }
  return 0; 
}