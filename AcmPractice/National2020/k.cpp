#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;
const int MAX_N = 55;
struct point {
  long long x, y;
};

long long area(const point &A, const point &B, const point &C) {
  long long res = 0;
  res = (A.y + B.y) * (A.x - B.x) + (B.y + C.y) * (B.x - C.x) + (C.y + A.y) * (C.x - A.x);
  res = abs(res);
  return res;
}

bool isInside(const point &A, const point &B, const point &C, const point &D) {
  if (area(B, C, D) == area(A, B, C) + area(A, C, D) + area(A, B, D)) {
    return true;
  }
  else {
    return false;
  }
}

int n;
point a[MAX_N];

int main () {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y;
    }
    int ans = 0;
    for (int first = 1; first <= n; first++) {
      for (int second = first + 1; second <= n; second++) {
        for (int third = second + 1; third <= n; third++) {
          for (int fourth = third + 1; fourth <= n; fourth++) {
            vector <point> listPoints;
            listPoints.push_back(a[first]);
            listPoints.push_back(a[second]);
            listPoints.push_back(a[third]);
            listPoints.push_back(a[fourth]);
            bool checkInside = false;
            if (isInside(listPoints[0], listPoints[1], listPoints[2], listPoints[3]) == true) {
              checkInside = true;
            };
            if (isInside(listPoints[1], listPoints[0], listPoints[2], listPoints[3]) == true) {
              checkInside = true;
            };
            if (isInside(listPoints[2], listPoints[1], listPoints[0], listPoints[3]) == true) {
              checkInside = true;
            };
            if (isInside(listPoints[3], listPoints[1], listPoints[2], listPoints[0]) == true) {
              checkInside = true;
            };
            if (checkInside == false) {
              ans++;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}