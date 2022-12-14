#include <bits/stdc++.h>

using namespace std;
int numTest;
int a[105];
int n;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}