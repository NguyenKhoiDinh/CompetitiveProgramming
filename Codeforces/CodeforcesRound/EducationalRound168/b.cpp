#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s[2];
    int n;
    cin >> n; 
    cin >> s[0] >> s[1];
    vector <int> pos[2];
    for (int i = 0; i < n; i++) {
      if (s[0][i] == 'x') {
        pos[0].push_back(i); 
      }
      if (s[1][i] == 'x') {
        pos[1].push_back(i); 
      }
    }
    int ans = 0; 
    for (int i = 0; i < (int) pos[0].size() - 1; i++) {
      if (pos[0][i] + 2 == pos[0][i + 1]) {
        int y = pos[0][i] + 1; 
        if (s[1][y] == '.' && s[1][y - 1] == '.' && s[1][y + 1] == '.') {
          ans++; 
        }
      }
    }   
    for (int i = 0; i < (int) pos[1].size() - 1; i++) {
      if (pos[1][i] + 2 == pos[1][i + 1]) {
        int y = pos[1][i] + 1; 
        if (s[0][y] == '.' && s[0][y - 1] == '.' && s[0][y + 1] == '.') {
          ans++; 
        }
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}