#include <bits/stdc++.h> 

using namespace std; 
int a[5005]; 
int f[(1 << 20) + 5][23]; 

int main () {
  int n;
  long long k; 
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[a[i] & a[j]][0]++; 
    }
  }
  int total = (1 << 20) - 1; 
  for (int j = 1; j <= 20; j++) {
    for (int mask = 0; mask <= (1 << 20); mask++) {
      if ((mask & (1 << (j - 1))) == 0) {
        f[mask][j] = f[mask][j - 1]; 
      }                             
      else {
        f[mask][j] = f[mask][j - 1] + f[(mask - (1 << (j - 1)))][j - 1]; 
      }
    }
  }
  int p1 = -1, p2 = -1, p3 = -1, p4 = -1; 
  bool check = false; 
  for (int i = 1; i <= n; i++) {
    if (check == true) {
      break; 
    }
    for (int j = 1; j <= n; j++) {
      int value = a[i] & a[j];
      long long ways = f[total - value][20];
      if (k > ways) {
        k -= ways; 
      } 
      else {
        p1 = i;
        p2 = j;
        check = true; 
        break;   
      }
    }
  }
  check = false; 
  int value1 = a[p1] & a[p2]; 
  for (int i = 1; i <= n; i++) {
    if (check == true) {
      break; 
    }
    for (int j = 1; j <= n; j++) {
      int value2 = a[i] & a[j];
      if ((value1 & value2) == 0) {
        k--; 
        if (k == 0) {
          p3 = i;
          p4 = j;
          check = true;
          break; 
        }
      }  
    }
  }
  if (p1 == -1 || p2 == -1 || p3 == -1 || p4 == -1) {
    cout << -1; 
  }
  else {
    cout << p1 << ' ' << p2 << ' ' << p3 << ' ' << p4;
  }
  return 0; 
}