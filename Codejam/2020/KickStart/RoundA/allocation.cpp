#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
int numTest;
int a[MAX_N];
int n, m;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= m) {
        ans++;
        m -= a[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}