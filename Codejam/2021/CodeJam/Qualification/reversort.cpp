#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105;
int numTest;
int n;
int a[MAX_N];

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
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int mini = n + 1;
      int pos = -1;
      for (int j = i; j <= n; j++) {
        if (mini > a[j]) {
          mini = a[j];
          pos = j;
        }
      }
      sum += pos - i + 1;
      reverse(a + i, a + pos + 1);
    }
    cout << sum - 1 << endl;
  }
  return 0;
}