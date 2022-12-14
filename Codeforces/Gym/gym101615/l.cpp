#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;
double K, P, X;

int main () {
  cin >> K >> P >> X;
  double ans = 1000000007.00000;
  for (int number = 1; number <= 100000; number++) {
    double sum = number * X;
    sum += K / number * P;
    ans = min(ans, sum);
  }
  cout << fixed << setprecision(3) << ans;
  return 0;
}