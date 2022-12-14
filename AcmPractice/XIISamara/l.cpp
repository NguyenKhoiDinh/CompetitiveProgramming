#include <bits/stdc++.h> 

using namespace std;

double dist(double X1, double Y1, double X2, double Y2) {
  return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

int main () {
  double x1, x2, y1, y2, r1, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
    swap(r1, r2);
  }
  double D = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  double r = (r1 + r2 - D) / 2;
  double x = (D - r2 + r) / D * (x2 - x1) + x1;
  double y = (D - r2 + r) / D * (y2 - y1) + y1; 
  cout << fixed << setprecision(10) << x << ' ' << y << ' ' << r;
  return 0; 
}