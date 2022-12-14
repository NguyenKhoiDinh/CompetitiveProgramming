#include <bits/stdc++.h> 

using namespace std;
string s; 

int main () {
  cin >> s; 
  int len = (int) s.size(); 
  int cntDots = 0;
  for (int i = 0; i < len; i++) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      s[i] = s[i] - 'A' + 'a';
    }
  } 
  for (int i = 0; i < len; i++) {
    if (s[i] == '.') {
      cntDots++; 
    }
  }
  if (cntDots > 1) {
    cout << "no";
    return 0; 
  }
  if (len > 3 && s[len - 1] == 'y' && s[len - 2] == 'p' && s[len - 3] == '.') {
    cout << "yes";
  }
  else {
    cout << "no";
  }
  return 0;
}
                 
