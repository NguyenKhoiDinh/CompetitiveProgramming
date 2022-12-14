#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005;
int numTest;
int W, H, U, D, L, R;
double sumLog2[MAX_N];

void init() {
  for (int i = 2; i < MAX_N; i++) {
    sumLog2[i] = sumLog2[i - 1] + log2(i);
  }
}

double getProbality(int n, int k) {
  double ret = 0.0;
  for (int i = k; i <= n; i++) {
    double sum = sumLog2[n] - sumLog2[n - i] - sumLog2[i] - n;
    ret += pow(2.0, sum);
  }
  return ret;
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  init();
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> W >> H >> L >> U >> R >> D;
    double ans = 0.0;
    if (R != W && U >= 2) {
      ans += getProbality(R + U - 2, R);
    }
    if (D != H && L >= 2) {
      ans += getProbality(D + L - 2, D);
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
  return 0;
}