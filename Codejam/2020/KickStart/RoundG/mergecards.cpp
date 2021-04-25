#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 5005; 
int numTest;
int n; 
double a[MAX_N];
double prob[MAX_N][MAX_N];

void init() {
  prob[2][2] = prob[2][1] = 1.0;
  for (int i = 3; i < MAX_N; i++) {
    for (int j = 1; j <= i; j++) {
      if (j > 1) {
        prob[i][j] += 1.0 * (j - 1) * prob[i - 1][j - 1] + 1;
      }
      if (j < i) {
        prob[i][j] += 1.0 * (i - j) * prob[i - 1][j] + 1;
      }
      prob[i][j] *= 1.0 / (i - 1);
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  init();
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    double ans = 0.0; 
    for (int i = 1; i <= n; i++) {
      ans += prob[n][i] * a[i];
    }
    cout << fixed << setprecision(12) << ans << endl;
  }
  return 0;
}