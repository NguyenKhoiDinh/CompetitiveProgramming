#include <bits/stdc++.h> 

using namespace std;
string s[2]; 
int cnt[2][2]; 
int main () {
  cin >> s[0] >> s[1];
  int len = (int) s[0].size(); 
  for (int i = 0; i < len; i++) {
    cnt[s[0][i] == '#'][s[1][i] == '#']++; 
  }
  if (cnt[1][0] > 0 && cnt[0][1] > 0 && cnt[1][1] == 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= cnt[1][0]; i++) {
    cout << '#';
  }
  for (int i = 1; i <= cnt[1][1]; i++) {
    cout << '#';
  }
  for (int i = 1; i <= cnt[0][1]; i++) {
    cout << '.';
  }
  for (int i = 1; i <= cnt[0][0]; i++) {
    cout << '.';
  }
  cout << endl;
  for (int i = 1; i <= cnt[1][0]; i++) {
    cout << '.';
  }
  for (int i = 1; i <= cnt[1][1]; i++) {
    cout << '#';
  }
  for (int i = 1; i <= cnt[0][1]; i++) {
    cout << '#';
  }
  for (int i = 1; i <= cnt[0][0]; i++) {
    cout << '.';
  }
  return 0; 
}
