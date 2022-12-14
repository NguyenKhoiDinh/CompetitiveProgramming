#include <bits/stdc++.h>

using namespace std;
int numTest;
double dp[1000005];
double sum[1000005];
const double GAM = 0.57721566990018758;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    int n;
    cin >> n;
    dp[0] = 0.000;
    sum[0] = 0.000;
    for (int i = 1; i <= n; i++) {
      dp[i] = 1.0 + 1.0 * sum[i - 1] / (double) i;
      sum[i] = sum[i - 1] + dp[i];
    }
    if (n <= 1000000) {
      cout << fixed << setprecision(10) << dp[n] << endl;
    }
    else {
      cout << fixed << setprecision(10) << (double) log(n) + dp[n] << endl;   
    }
  }     
  return 0;
}