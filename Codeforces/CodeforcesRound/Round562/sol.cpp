#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 20;
int test;
int n, D;
char a[20][20];

int main () {
  //freopen("AC4.INP", "r", stdin);
  //freopen("AC4.OUT", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> D >> n;
    D = 15;
    cout << D << ' ' << D << endl;
    for (int i = 1; i <= D; i++) {
      for (int j = 1; j <= D; j++) {
        a[i][j] = 'C';
        if (j % 4 == 1) {
          a[i][j] = 'A';
        }
      }
    }
    for (int i = 2; i < D; i++) {
      for (int j = 2; j <= D; j += 2) {
        if (n >= 3) {
          a[i][j] = 'B';
          n -= 3;
        }
      }
    }
    for (int j = 2; j <= D; j += 2) {
      if (n > 0) {
        a[1][j] = 'B';
        n--;
      }
      if (n > 0) {
        a[D][j] = 'B';
        n--;
      }
    }
    for (int i = 1; i <= D; i++) {
      for (int j = 1; j <= D; j++) {
        cout << a[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}