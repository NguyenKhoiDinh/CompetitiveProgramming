#include <bits/stdc++.h>

using namespace std;
int numTest; 
int n;
string s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    cin >> s; 
    int x = 0, y = 0;
    int numbN = 0, numbS = 0, numbE = 0, numbW = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'N') {
        numbN++; 
        x--; 
      }
      else if (s[i] == 'S') {
        numbS++; 
        x++; 
      }
      else if (s[i] == 'E') {
        numbE++; 
        y++; 
      }
      else {
        numbW++; 
        y--; 
      }
    }
    if ((abs(x) % 2 == 1) || (abs(y) % 2 == 1)) {
      cout << "NO" << endl; 
      continue; 
    }
    string ans = ""; 
    for (int i = 0; i < n; i++) {
      ans += 'R'; 
    }
    x /= 2; 
    y /= 2; 
    int curx = 0, cury = 0; 
    for (int i = 0; i < n; i++) {
      if (s[i] == 'N' && x < 0 && curx > x) {
        curx--; 
        ans[i] = 'H'; 
      }
      else if (s[i] == 'S' && x > 0 && curx < x) {
        curx++;
        ans[i] = 'H'; 
      }
      else if (s[i] == 'E' && y > 0 && cury < y) {
        cury++; 
        ans[i] = 'H'; 
      }
      else if (s[i] == 'W' && y < 0 && cury > y) {
        cury--;
        ans[i] = 'H'; 
      }
    }
    bool check = true; 
    for (int i = 0; i < (int) ans.size(); i++) {
      if (ans[i] != ans[0]) {
        check = false;
      }
    }
    if (check == true && numbN % 2 == 0 && numbS % 2 == 0 && numbW % 2 == 0 && numbE % 2 == 0) {
      numbN /= 2;
      numbS /= 2;
      numbW /= 2; 
      numbE /= 2; 
      for (int i = 0; i < n; i++) {
        if (s[i] == 'N' && numbN > 0) {
          ans[i] = 'H';
          numbN--;
        }
        else if (s[i] == 'S' && numbS > 0) {
          ans[i] = 'H';
          numbS--; 
        }
        else if (s[i] == 'E' && numbE > 0) {
          ans[i] = 'H';
          numbE--; 
        }
        else if (s[i] == 'W' && numbW > 0) {
          ans[i] = 'H'; 
          numbW--; 
        }
      }
      cout << ans << endl;
      continue;
    }
    if (check == true && numbN == numbS && numbW == numbE && numbN > 0 && numbS > 0 && numbW > 0 && numbE > 0) {
      for (int i = 0; i < (int) ans.size(); i++) {
        if (s[i] == 'N' || s[i] == 'S') {
          ans[i] = 'H'; 
        }
      }
      cout << ans << endl;
      continue;
    }
    if (check == true && numbN == numbS && numbN > 1) {
      bool okN = false, okS = false;
      for (int i = 0; i < (int) ans.size(); i++) {
        if (s[i] == 'N' && okN == false) {
          ans[i] = 'H';
          okN = true; 
        }
        if (s[i] == 'S' && okS == false) {
          ans[i] = 'H';
          okS = true; 
        }
      }
      cout << ans << endl;
      continue; 
    }
    if (check == true && numbE == numbW && numbE > 1) {
      bool okE = false, okW = false;
      for (int i = 0; i < (int) ans.size(); i++) {
        if (s[i] == 'W' && okW == false) {
          ans[i] = 'H';
          okW = true; 
        }
        if (s[i] == 'E' && okE == false) {
          ans[i] = 'H';
          okE = true; 
        }
      }
      cout << ans << endl;
      continue; 
    }                                                                             
    cout << (check == true ? "NO" : ans) << endl;
  }
  return 0; 
}