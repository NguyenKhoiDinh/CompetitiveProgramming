#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
int numTest;
int a[MAX_N];
int n;

int main () {
 cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    int maxi = -1;
    for (int i = 1; i <= n; i++) {
      bool flag = false;
      if (maxi < a[i]) {
        maxi = a[i];
        flag = true;
      }
      if (i < n && flag == true && a[i] > a[i + 1]) {
        ans++;
      }
      else if (i == n && flag == true) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}