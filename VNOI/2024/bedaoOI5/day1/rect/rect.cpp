#include <bits/stdc++.h> 

using namespace std;
int f[2005][2005]; 
int n, l, r; 
struct rectangle {
  int x1, y1, x2, y2; 
};
rectangle a[200005]; 

int main () {
  freopen("rect.inp", "r", stdin);
  freopen("rect.out", "w", stdout);
  bool isSub2 = true;
  bool isSub3 = false;   
  cin >> n >> l >> r; 
  if (l == 1 && r == n) {
    isSub3 = true; 
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    a[i].x1++;
    a[i].y1++;
    a[i].x2++;
    a[i].y2++; 
    if (a[i].x1 > 2001 || a[i].y1 > 2001 || a[i].x2 > 2001 || a[i].y2 > 2001) {
      isSub2 = false; 
    } 
  }
  if (isSub2 == true) {
    for (int i = 1; i <= n; i++) {
      f[a[i].x1][a[i].y1]++;
      f[a[i].x1][a[i].y2 + 1]--;
      f[a[i].x2 + 1][a[i].y1]--;
      f[a[i].x2 + 1][a[i].y2 + 1]++;     
    }
    for (int y = 1; y <= 2001; y++) {
      for (int x = 1; x <= 2001; x++) {
        f[x][y] += f[x - 1][y]; 
      }
    }
    for (int x = 1; x <= 2001; x++) {
      for (int y = 1; y <= 2001; y++) {
        f[x][y] += f[x][y - 1]; 
      }
    }
    int ans = 0; 
    for (int x = 1; x <= 2001; x++) {
      for (int y = 1; y <= 2001; y++) {
        if (l <= f[x][y] && f[x][y] <= r) {
          ans++; 
        }
      }
    }
    cout << ans << endl; 
    return 0; 
  }
  return 0; 
}