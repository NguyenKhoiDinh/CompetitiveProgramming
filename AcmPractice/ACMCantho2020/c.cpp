#include <iostream>

using namespace std;

struct point {
  double x, y;
};
double a, b, c1, c2;
int numTest, n;
point listPoints[6];

int check(double c) {
  int res = -1;
  for (int i = 0; i < n; i++) {
    if (b != 0) {
      double Y = 1.0 * (1.0 * c - a * listPoints[i].x) / b;
      if (1.0 * listPoints[i].y < Y) {
        if (res == 2) {
          return 1;
        }
        res = 0;
      }
      else if (1.0 * listPoints[i].y > Y) {
        if (res == 0) {
          return 1;
        }
        res = 2;
      }
    }
    else {
      double X = 1.0 * c / a;
      if (1.0 * listPoints[i].x < X) {
        if (res == 2) {
          return 1;
        }
        res = 0;
      }
      else if (1.0 * listPoints[i].x > X) {
        if (res == 0) {
          return 1;
        }
        res = 2;
      }
    }
  }
  return res;
}

int main () {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> a >> b >> c1 >> c2;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> listPoints[i].x >> listPoints[i].y;
    }
    if ((check(c1) == 0 && check(c2) == 0) || (check(c1) == 2 && check(c2) == 2)) {
      cout << "NO";
    }
    else {
      cout << "YES";
    }
    cout << endl;
  }
  return 0;
}