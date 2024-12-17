#include <bits/stdc++.h> 

using namespace std;
const int mod = 1000000007; 
int n;
int f[2005][2005];
string s; 

int main () {
  freopen("input.txt", "r", stdin);
  cin >> n;
  cin >> s; 
  f[0][0] = 1; 
  for (int i = 0; i < n; i++) {
    for (int freeOpen = 0; freeOpen <= i; freeOpen++) {
      if (f[i][freeOpen] > 0) {
        if (s[i] == '(' || s[i] == '?') {
          (f[i + 1][freeOpen + 1] += f[i][freeOpen]) %= mod; 
        }
        if ((s[i] == ')' || s[i] == '?') && freeOpen > 0) {
          (f[i + 1][freeOpen - 1] += f[i][freeOpen]) %= mod; 
        } 
      }
    }
  }
  cout << f[n][0];
  return 0; 
}
