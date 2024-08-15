#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
int n;
int sumCol[1005][1005], sumRow[1005][1005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    vector <string> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i]; 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sumRow[i][j] = 0;
        sumCol[i][j] = 0;    
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sumRow[i][j] = (j == 0 ? 0 : sumRow[i][j - 1]) + a[i][j] - '0'; 
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        sumCol[i][j] = (i == 0 ? 0 : sumCol[i - 1][j]) + a[i][j] - '0'; 
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        bool ok = false; 
        for (int t = 1; t < n; t++) {
          if (i - t >= 0 && i + t < n) {
            int l = max(0, j - t); 
            int r = min(n - 1, j + t);
            if (sumRow[i - t][r] - (l == 0 ? 0 : sumRow[i - t][l - 1]) != 0 && sumRow[i + t][r] - (l == 0 ? 0 : sumRow[i + t][l - 1]) != 0) {
              ok = true;
              break; 
            } 
          } 
          if (j - t >= 0 && j + t < n) {
            int l = max(0, i - t); 
            int r = min(n - 1, i + t); 
            if (sumCol[r][j - t] - (l == 0 ? 0 : sumCol[l - 1][j - t]) != 0 && sumCol[r][j + t] - (l == 0 ? 0 : sumCol[l - 1][j + t]) != 0) {
              ok = true;
              break; 
            } 
          }
        }
        cout << (ok == false ? 0 : 1); 
      }
      cout << endl; 
    }
  }
  return 0; 
}