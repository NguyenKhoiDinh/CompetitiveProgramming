#include <bits/stdc++.h> 

using namespace std;
int numTest;
int a[200005];
int n;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (a[1] != n && a[n] != n) {
      cout << -1 << endl;
      continue; 
    }
    int l = 1, r = n - 1; 
    if (a[1] == n) {
      l++;
      r++;
    }
    for (int i = r; i >= l; i--) {
      cout << a[i] << ' ';
    }
    cout << n << endl;
  }
  return 0; 
}