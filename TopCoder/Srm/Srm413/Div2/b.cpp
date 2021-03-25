#include <bits/stdc++.h>

using namespace std;

int process(double x, vector <int> &a) {
  int n = (int) a.size();
  for (int i = 0; i < n; i++) {
    double value = 1.0 * x * (i + 1);
    int v = (int) value;
    if (v < a[i]) {
      return 0;
    }
    else if (v > a[i]) {
      return 2;
    }
  }
  return 1;
}

class ArithmeticProgression {
  public:
  double minCommonDifference(int a0, vector <int> seq) {
    int n = (int) seq.size();
    for (int i = 0; i < n; i++) {
      seq[i] -= a0;
    }
    double l = 0; double r = 2000007.00000;
    double ans = -1.0;
    for (int step = 1; step <= 100; step++) {
      double mid = (l + r) / 2.0;
      int check = process(mid, seq);
      if (check == 0) {
        l = mid;
      }
      else if (check == 1) {
        r = mid;
        ans = mid;
      }
      else {
        r = mid;
      }
    }
    return ans;
  }
};

ArithmeticProgression A;

int main () {
  cout << A.minCommonDifference(0,
{6, 13, 20, 27});
  return 0;
}