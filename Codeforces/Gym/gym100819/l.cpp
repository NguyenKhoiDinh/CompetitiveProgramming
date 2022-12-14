#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
struct quiz {
  double p, v;
  bool safeFlag;
};
quiz a[100100];
int n;
double W;
double P[100100];

int main() {
  cin >> n >> W;
  P[0] = 1.0;
  for (int i = 1; i <= n; i++) {
	  string buff;
	  cin >> buff >> a[i].p >> a[i].v;
	  a[i].safeFlag = buff[0] == 's';
	  P[i] = P[i - 1] * a[i].p;
  }
  double hh = 0.0, hmax = 0.0;
  int lsti = 0;
  for (int i = 1; i <= n; i++) {
	  double h = hh + (P[lsti] - P[i]) * log(1.0 + a[lsti].v / W) + P[i] * log(1.0 + a[i].v / W);
	  if (hmax < h) {
		  hmax = h;
	  }
	  if (a[i].safeFlag == true) {
		  hh += (P[lsti] - P[i]) * log(1.0 + a[lsti].v / W);
		  lsti = i;
	  }
  }
  cout << '$';
  cout << fixed << setprecision(2) << W * (exp(hmax) - 1.0);
  return 0;
}
