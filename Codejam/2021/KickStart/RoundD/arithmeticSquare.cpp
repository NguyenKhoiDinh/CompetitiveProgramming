#include <bits/stdc++.h>

using namespace std;
int numTest;
int a[3][3];
int ans = -1;

bool check(int a, int b, int c) {
  return (b - a == c - b);
}

void solve(int v) {
  int total = 0;
  total += check(a[0][1], v, a[2][1]);
  total += check(a[1][0], v, a[1][2]);
  total += check(a[0][0], v, a[2][2]);
  total += check(a[2][0], v, a[0][2]);
  total += check(a[0][0], a[0][1], a[0][2]);
  total += check(a[2][0], a[2][1], a[2][2]);
  total += check(a[0][0], a[1][0], a[2][0]);
  total += check(a[0][2], a[1][2], a[2][2]);
  ans = max(ans, total);
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    cin >> a[1][0] >> a[1][2];
    cin >> a[2][0] >> a[2][1] >> a[2][2];
    ans = -1;
    int v = (a[1][0] + a[1][2]) / 2;
    solve(v);
    v = (a[0][1] + a[2][1]) / 2;
    solve(v);
    v = (a[0][0] + a[2][2]) / 2;
    solve(v);
    v = (a[2][0] + a[0][2]) / 2;
    solve(v);
    cout << ans << endl;
  }
  return 0;
}