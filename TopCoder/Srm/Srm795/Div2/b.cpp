#include <bits/stdc++.h>

using namespace std;

double calc(int a, int b, int c) {
  double x = 1.0 * (a * a - b * b + c * c) / (2.0 * c);
  double h = sqrt(a * a - x * x) + 1;
  return 0.5 * c * h;
}

class VertexMove {
  public:
  double largestTriangleArea(int a, int b, int c) {
    double res = calc(a, b, c);
    res = max(res, calc(b, c, a));
    res = max(res, calc(a, c, b));
    return res;
  }
};

VertexMove V;

int main () {
  cout << V.largestTriangleArea(12, 13, 16);
  return 0;
}