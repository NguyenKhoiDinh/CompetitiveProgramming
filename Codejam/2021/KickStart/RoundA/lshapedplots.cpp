#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 1005;
int numTest;
int R, C, res = 0;
int a[MAX_N][MAX_N];
int sumRow[MAX_N][MAX_N];
int sumCol[MAX_N][MAX_N];

void solve(int directRow, int directCol, int x, int y) {
  int l, r;
  int len1 = -1, len2 = -1;
  if (directRow == 0) {
    r = y;
    l = 1;
  }
  else {
    l = y;
    r = C;
  }
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (directRow == 0) {
      int numOnes = sumRow[x][y] - sumRow[x][mid - 1];
      if (numOnes == y - mid + 1) {
        len1 = numOnes;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    else {
      int numOnes = sumRow[x][mid] - sumRow[x][y - 1];
      if (numOnes == mid - y + 1) {
        len1 = numOnes;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
  }
  if (directCol == 0) {
    l = 1;
    r = x;
  }
  else {
    l = x;
    r = R;
  }
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (directCol == 0) {
      int numOnes = sumCol[x][y] - sumCol[mid - 1][y];
      if (numOnes == x - mid + 1) {
        len2 = numOnes;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    else {
      int numOnes = sumCol[mid][y] - sumCol[x - 1][y];
      if (numOnes == mid - x + 1) {
        len2 = numOnes;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
  }
  if (len1 > 1 && len2 > 3) {
    res += min(len1, len2 / 2) - 1;
  }
  if (len1 > 3 && len2 > 1) {
    res += min(len1 / 2, len2) - 1;
  }
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
        sumRow[i][j] = 0;
        sumCol[i][j] = 0;
      }
    }
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        sumRow[i][j] = sumRow[i][j - 1] + a[i][j];
      }
    }
    for (int j = 1; j <= C; j++) {
      for (int i = 1; i <= R; i++) {
        sumCol[i][j] = sumCol[i - 1][j] + a[i][j];
      }
    }
    res = 0;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (a[i][j] == 0) {
          continue;
        }
        solve(0, 0, i, j);
        solve(0, 1, i, j);
        solve(1, 0, i, j);
        solve(1, 1, i, j);
      }
    }
    cout << res << endl;
  }
  return 0;
}