#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
const int MAX_N = 300005; 
int numTest; 
int a[MAX_N];
int n; 
int F[MAX_N], revF[MAX_N];

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    if (n <= 2) {
      cout << n << endl; 
      continue; 
    }
    if (n == 3) {
      if (abs(a[3] - a[1]) % 2 == 0) {
        cout << n << endl; 
      }
      else {
        cout << 2 << endl; 
      }
      continue; 
    }
    F[1] = 1; 
    F[2] = 2; 
    int diff = (a[2] - a[1]); 
    for (int i = 3; i <= n; i++) {
      int d = (a[i] - a[i - 1]); 
      if (d == diff) {
        F[i] = F[i - 1] + 1; 
      }
      else {
        F[i] = 2; 
        diff = d; 
      }
    }
    revF[n] = 1; 
    revF[n - 1] = 2; 
    diff = (a[n] - a[n - 1]); 
    for (int i = n - 2; i >= 1; i--) {
      int d = (a[i + 1] - a[i]); 
      if (d == diff) {
        revF[i] = revF[i + 1] + 1; 
      }
      else {
        revF[i] = 2; 
        diff = d; 
      }
    }
    int ans = 2; 
    for (int i = 1; i <= n; i++) {
      ans = max(ans, F[i]);
    }
    for (int i = 2; i <= n; i++) {
      ans = max(ans, F[i - 1] + 1); 
    }
    for (int i = n - 1; i >= 1; i--) {
      ans = max(ans, revF[i + 1] + 1);
    }
    for (int i = 2; i < n; i++) {
      if ((a[i + 1] - a[i - 1]) % 2 != 0) {
        continue; 
      }
      int val = 1; 
      int diff = (a[i + 1] - a[i - 1]) / 2; 
      if (i >= 3 && a[i - 1] - a[i - 2] == diff) {
        val += F[i - 1]; 
      }
      else {
        val++; 
      }
      if (i <= n - 2 && a[i + 2] - a[i + 1] == diff) {
        val += revF[i + 1]; 
      }
      else {
        val++; 
      }
      ans = max(ans, val);
    }
    cout << ans << endl;
  }
  return 0;
}