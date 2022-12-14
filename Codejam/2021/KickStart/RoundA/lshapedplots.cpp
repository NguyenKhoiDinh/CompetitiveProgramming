#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
const int MAX_N = 1005;
int numTest;
int R, C, res = 0;
int a[MAX_N][MAX_N];
int Up[MAX_N][MAX_N], Right[MAX_N][MAX_N], Down[MAX_N][MAX_N], Left[MAX_N][MAX_N];

int calc(int x, int y) {
  int sum = 0; 
  if (min(x / 2, y) > 1) {
    sum += min(x / 2, y) - 1; 
  }
  if (min(x, y / 2) > 1) {
    sum += min(x, y / 2) - 1; 
  }
  return sum;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        cin >> a[i][j]; 
      }
    }
    for (int i = 0; i <= R + 1; i++) {
      for (int j = 0; j <= C + 1; j++) {
        Up[i][j] = 0;
        Right[i][j] = 0;
        Down[i][j] = 0;
        Left[i][j] = 0;
      }
    }
    for (int j = 1; j <= C; j++) {
      for (int i = 1; i <= R; i++) {
        if (a[i][j] == 1) {
          Up[i][j] = Up[i - 1][j] + 1; 
        }
      }
      for (int i = R; i >= 1; i--) {
        if (a[i][j] == 1) {
          Down[i][j] = Down[i + 1][j] + 1; 
        }
      }
    }
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (a[i][j] == 1) {
          Left[i][j] = Left[i][j - 1] + 1; 
        }
      }
      for (int j = C; j >= 1; j--) {
        if (a[i][j] == 1) {
          Right[i][j] = Right[i][j + 1] + 1; 
        }
      }
    }
    long long ans = 0LL; 
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (a[i][j] == 1) {
          int U = Up[i][j];
          int R = Right[i][j];
          int D = Down[i][j];
          int L = Left[i][j];
          ans += calc(U, R);
          ans += calc(R, D);
          ans += calc(D, L);
          ans += calc(L, U); 
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}