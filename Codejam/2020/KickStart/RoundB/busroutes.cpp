#include <bits/stdc++.h>

using namespace std;
int numTest;
long long D;
int n;
int a[105];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long maxDay = D;
    for (int i = n; i >= 1; i--) {
      maxDay = maxDay / a[i] * a[i];
    }
    cout << maxDay << endl;
  }
  return 0;
}