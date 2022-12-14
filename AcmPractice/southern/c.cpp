#include <bits/stdc++.h> 

using namespace std;

int main () {
  string s;
  cin >> s; 
  int step;
  cin >> step; 
  int minChar = 'z' + 5; 
  vector <int> listPos; 
  for (int i = 0; i < (int) s.size(); i++) {
    if (minChar > s[i]) {
      minChar = s[i];
      listPos.clear(); 
      listPos.push_back(i); 
    }
    else if (minChar == s[i]) {
      listPos.push_back(i); 
    }
  }
  char c1 = (char) minChar;
  char c2 = 'z' + 5; 
  for (int i = 0; i < (int) listPos.size(); i++) {
    int pos = listPos[i]; 
    if (pos > 0) {
      c2 = min(c2, s[pos - 1]);  
    }
    if (pos < (int) s.size() - 1) {
      c2 = min(c2, s[pos + 1]); 
    }
  } 
  c2 = (char) c2; 
  for (int i = 1; i <= step; i++) {
    cout << (i % 2 == 1 ? c1 : c2); 
  }
  return 0; 
}