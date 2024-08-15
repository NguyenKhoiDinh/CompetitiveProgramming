#include <bits/stdc++.h> 

using namespace std; 

int main () {
  string s; 
  int n;
  cin >> n >> s; 
  string rev_s = s; 
  reverse(rev_s.begin(), rev_s.end()); 
  if (s != rev_s) {
    cout << n; 
    return 0; 
  }
  bool check = true; 
  for (int i = 1; i < n; i++) {
    if (s[i] != s[0]) {
      check = false; 
    }
  }
  if (check == true) {
    cout << 0; 
  }
  else {
    cout << n - 1; 
  }
  return 0; 
}