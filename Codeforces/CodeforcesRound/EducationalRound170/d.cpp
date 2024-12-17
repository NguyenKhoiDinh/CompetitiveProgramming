#include <bits/stdc++.h>

using namespace std;
int n, m;
int r[2000005]; 
vector <int> position; 
int strength[5005][5005], intelligence[5005][5005]; 
int f[5005][5005]; 

int main () {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    if (r[i] == 0) {
      position.push_back(i);
    }
  } 
  for (int i = 0; i < m; i++) {
    int nextPos = (i < m - 1 ? position[i + 1] - 1 : n);
    for (int j = position[i] + 1; j <= nextPos; j++) {
      if (r[j] > 0) {
        intelligence[i][r[j]]++; 
      }
      else if (r[j] < 0) {
        strength[i][-r[j]]++; 
      }
    }
    for (int j = 1; j <= m; j++) {
      intelligence[i][j] += intelligence[i][j - 1]; 
      strength[i][j] += strength[i][j - 1]; 
    } 
  }
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= i; j++) {
      f[i][j] = -1; 
    }  
  }
  f[0][0] = 0; 
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++) {
      if (f[i][j] == -1) {
        continue; 
      }
      int curStrength = i - j;
      f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + strength[i][curStrength] + intelligence[i][j + 1]); 
      f[i + 1][j] = max(f[i + 1][j], f[i][j] + strength[i][curStrength + 1] + intelligence[i][j]); 
    }
  }
  int ans = -1; 
  for (int j = 0; j <= m; j++) {
    ans = max(ans, f[m][j]); 
  }
  cout << ans;
  return 0; 
}