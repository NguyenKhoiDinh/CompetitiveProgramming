#include <bits/stdc++.h>

using namespace std;

class SymmetryDetection {
  public:
  string detect(vector <string> a) {
    bool ver = true, hor = true;
    int n = (int) a.size();
    int m = (int) a[0].size();
    for (int i = 0; i < n; i++) {
      int l = 0;
      int r = m - 1;
      while (l <= r) {
        if (a[i][l] != a[i][r]) {
          ver = false;
          break;
        }
        else {
          l++;
          r--;
        }
      }
    }
    for (int j = 0; j < m; j++) {
      int l = 0;
      int r = n - 1;
      while (l <= r) {
        if (a[l][j] != a[r][j]) {
          hor = false;
          break;
        }
        else {
          l++;
          r--;
        }
      }
    }
    if (ver == false && hor == false) {
      return "Neither";
    }
    else if (ver == true && hor == true) {
      return "Both";
    }
    else if (ver == true) {
      return "Vertically symmetric";
    }
    else {
      return "Horizontally symmetric";
    }
  }
};

int main () {
  return 0;
}