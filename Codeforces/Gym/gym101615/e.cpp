#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;
const int MAX_N = 105;
const double EPS = 1e-9;
int n;
double X, V;
double l[MAX_N], r[MAX_N], v[MAX_N];
double C = 0.0;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> X >> V;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i] >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    C += (r[i] - l[i]) * v[i];
  }
  double vy = -C / X;
  if (vy - EPS > V) {
    cout << "Too hard";
  }
  else {
    double vx = sqrt(V * V - vy * vy);
    if (vx * 2 + EPS < V) {
      cout << "Too hard";
    }
    else {
      cout << fixed << setprecision(3) << X / vx;
    }
  }
  return 0;
}