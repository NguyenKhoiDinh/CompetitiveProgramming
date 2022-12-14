#include <bits/stdc++.h> 

using namespace std;
bool mark[1005];
string s;

bool check(char c1, char c2, char c3) {
  memset(mark, false, sizeof(mark));
  int last = -1;
  int numb1 = 0, numb2 = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == c1) {
      numb1++;
      last = i;
      mark[i] = true; 
    }
  }
  for (int i = last + 1; i < (int) s.size(); i++) {
    if (s[i] == c2) {
      numb1++;
      mark[i] = true;
    }
  }    
  last = -1;
  for (int i = 0; i < (int) s.size(); i++) {
    if (mark[i] == false && s[i] == c2) {
      numb2++;
      mark[i] = true;
      last = i;
    }
  }
  for (int i = last + 1; i < (int) s.size(); i++) {
    if (mark[i] == false && s[i] == c3) {
      numb2++;
      mark[i] = true;
    }
  }
  return (numb1 + numb2 == (int) s.size());
}

int main () {
  cin >> s;
  bool ans = false;
  ans |= check('R', 'G', 'B');
  ans |= check('R', 'B', 'G');
  ans |= check('G', 'B', 'R');
  ans |= check('G', 'R', 'B');
  ans |= check('B', 'G', 'R');
  ans |= check('B', 'R', 'G');
  cout << (ans == true ? "YES" : "NO");
  return 0; 
}