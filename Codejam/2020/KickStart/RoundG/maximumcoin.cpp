#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005; 
int numTest;
long long a[MAX_N][MAX_N];
int n;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    long long ans = -1; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ans = max(ans, a[i][j]);
        if (i < n && j < n) {
          a[i + 1][j + 1] += a[i][j];
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}