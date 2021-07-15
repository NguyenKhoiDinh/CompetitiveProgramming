#include <bits/stdc++.h>

using namespace std;
int a[5];

int main () {
  cin >> a[1] >> a[2] >> a[3] >> a[4];
  if (a[1] + a[2] == a[3] + a[4] || a[1] + a[3] == a[2] + a[4] || a[1] + a[4] == a[2] + a[3]) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
  return 0;
}