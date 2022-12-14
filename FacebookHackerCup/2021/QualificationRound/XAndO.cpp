#include <bits/stdc++.h> 

using namespace std;
int numTest; 
string s[55];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int ans = 55;
    int ways = 0;
    int numRow = 0, numCol = 0;
    int posRow = -1, posCol = -1;
    for (int row = 0; row < n; row++) {
      int cntO = 0;
      int cntX = 0;
      for (int j = 0; j < n; j++) {
        if (s[row][j] == 'X') {
          cntX++;
        }  
        if (s[row][j] == 'O') {
          cntO++;
        }
      }
      if (cntO > 0) {
        continue;
      }
      if (ans > n - cntX) {
        ans = n - cntX;
        ways = 1;
        numRow = 1;
        posRow = row;
      }
      else if (ans == n - cntX) {
        ways++;
        numRow++;
        posRow = row;
      }
    }
    for (int col = 0; col < n; col++) {
      int cntO = 0;
      int cntX = 0;
      for (int i = 0; i < n; i++) {
        if (s[i][col] == 'X') {
          cntX++;
        }  
        if (s[i][col] == 'O') {
          cntO++;
        }
      }
      if (cntO > 0) {
        continue;
      }
      if (ans > n - cntX) {
        ans = n - cntX;
        ways = 1;
        numRow = 0;
        numCol = 1;
        posCol = col;
      }
      else if (ans == n - cntX) {
        ways++;
        numCol++;
        posCol = col; 
      }
    }
    if (ans == 1) {
      ways = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (s[i][j] == '.') {
            int nRow = 0;
            for (int k = 0; k < n; k++) {
              if (s[i][k] == 'X') {
                nRow++;
              }
            }
            if (nRow == n - 1) {
              ways++;
              continue;
            }
            int nCol = 0;
            for (int k = 0; k < n; k++) {
              if (s[k][j] == 'X') {
                nCol++;
              }
            } 
            if (nCol == n - 1) {
              ways++;
              continue;
            }
          }
        }
      }
    }
    if (ways == 0) {
      cout << "Impossible" << endl;
    }
    else {
      cout << ans << ' ' << ways << endl;
    }
  }
  return 0; 
}