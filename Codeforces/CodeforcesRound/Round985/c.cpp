#include <bits/stdc++.h>

using namespace std;
const int inf = -1000000007;
int f[300005][3];
int n;
int a[300005];  
int calculate(int x, int value) {
  int ret = 0;
  if (value > x) {
    ret++; 
  }
  else if (value < x) {
    ret--;
  }
  return ret; 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      f[i][0] = inf; 
      f[i][1] = inf; 
      f[i][2] = inf; 
    }
    f[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int state = 0; state <= 2; state++) {
        if (f[i][state] == inf) {
          continue; 
        }
        if (state == 0) {
          f[i + 1][0] = max(f[i + 1][0], f[i][state] + calculate(f[i][state], a[i + 1]));
          f[i + 1][1] = max(f[i + 1][1], f[i][state]);    
        }
        else if (state == 1) {
          f[i + 1][1] = max(f[i + 1][1], f[i][state]); 
          f[i + 1][2] = max(f[i + 1][2], f[i][state] + calculate(f[i][state], a[i + 1])); 
        }
        else {
          f[i + 1][2] = max(f[i + 1][2], f[i][state] + calculate(f[i][state], a[i + 1])); 
        }
      }
    }
    cout << max(f[n][1], f[n][2]) << endl;
  }
  return 0; 
}