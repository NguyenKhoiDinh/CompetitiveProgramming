#include <bits/stdc++.h>
using namespace std;
double A, H;

double f(const double &x) {
  if (3.0 * x >= H) {
    return 100.0; 
  }
  else if (6.0 * x >= H) {
    return (600 - 6.0 * A) * x / H + 2 * A - 100.0;
  }
  else {
    return 6 * A * x / H;
  }
}

int main(){
  cin>>A>>H;
  double lo = 0.0, hi = H; 
  for (int i = 1; i <= 1000; i++) {
    double u = (2.0 * lo + hi) / 3.0;
    double v = (lo + 2.0 * hi) / 3.0;
    if ((H - u) * f(u) > (H - v) * f(v)) {
      hi = v; 
    }
    else {
      lo = u; 
    }
  }
  cout << fixed << setprecision(12) << (H - lo) * f(lo); 
  return 0; 
}