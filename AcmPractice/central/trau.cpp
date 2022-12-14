#include <bits/stdc++.h> 

using namespace std;

int main () {
  string s; 
  cin >> s; 
  int ans = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    for (int j = i; j < (int) s.size(); j++) {
      set <char> S; 
      for (int k = i; k <= j; k++) {
        S.insert(s[k]); 
      }
      ans += (int) S.size(); 
    }
  }
  cout << ans; 
  return 0; 
}