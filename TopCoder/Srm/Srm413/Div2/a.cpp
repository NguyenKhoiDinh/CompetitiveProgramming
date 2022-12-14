#include <bits/stdc++.h>

using namespace std;

class Subway2 {
  public:
  double minTime(int length, int maxA, int maxV) {
    double t = 1.0 * maxV / maxA;
    double mid = 1.0 * length / 2.0;
    double X = min(0.5 * maxA * t * t, mid);
    double ans = 0.0;
    ans += sqrt(X / maxA * 2.0);
    if (X < mid) {
      ans += (mid - X) / maxV;
    }
    ans *= 2.0;
    return ans;
  }
};

int main () {
  return 0;
}