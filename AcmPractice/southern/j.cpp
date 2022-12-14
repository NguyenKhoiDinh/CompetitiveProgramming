#include <bits/stdc++.h> 

using namespace std;
char a[3005][3005]; 
int n, m; 
int Up[3005][3005], Left[3005][3005], Right[3005][3005], Down[3005][3005]; 

int main () {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j]; 
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      Up[i][j] = (a[i][j] == '0' ? 0 : Up[i - 1][j] + 1);
    }
    for (int i = n; i >= 1; i--) {
      Down[i][j] = (a[i][j] == '0' ? 0 : Down[i + 1][j] + 1); 
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      Left[i][j] = (a[i][j] == '0' ? 0 : Left[i][j - 1] + 1); 
    }
    for (int j = m; j >= 1; j--) {
      Right[i][j] = (a[i][j] == '0' ? 0 : Right[i][j + 1] + 1); 
    }
  }
  int maxLength = -1; 
  int resx = -1, resy = -1; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '1') {
        int minLength = min(min(Up[i][j], Down[i][j]), min(Left[i][j], Right[i][j])); 
        if (maxLength < minLength) {
          maxLength = minLength; 
          resx = i;
          resy = j; 
        }
      }
    }
  }
  if (maxLength == -1) {
    cout << -1;
    return 0; 
  }
  cout << maxLength * 4 - 3 << endl;
  cout << resx << ' ' << resy; 
  return 0; 
}