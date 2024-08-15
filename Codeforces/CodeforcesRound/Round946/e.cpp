#include <bits/stdc++.h>

using namespace std;
struct happy {
  int c, h; 
};
int numTest; 
long long f[52][100005]; 
int n, x; 
happy a[52]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> x;
    int sumHappy = 0; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i].c >> a[i].h; 
      sumHappy += a[i].h; 
    } 
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= sumHappy; j++) {
        f[i][j] = -1; 
      }
    }
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= sumHappy; j++) {
        if (f[i][j] == -1) {
          continue; 
        }
        f[i + 1][j] = max(f[i + 1][j], f[i][j] + x);
        if (f[i][j] >= a[i + 1].c) {
          f[i + 1][j + a[i + 1].h] = max(f[i + 1][j + a[i + 1].h], f[i][j] - a[i + 1].c + x); 
        } 
      }
    }
    for (int j = sumHappy; j >= 0; j--) {
      if (f[n][j] != -1) {
        cout << j << endl;
        break;
      }
    } 
  }
  return 0; 
}