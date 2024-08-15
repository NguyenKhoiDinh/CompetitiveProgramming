#include <bits/stdc++.h>

using namespace std;
int numTest; 
int a[100005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k, h;
    cin >> n >> k >> h;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    sort(a + 1, a + n + 1); 
    int l = 1;
    int r = k; 
    bool ok = false;
    while (r <= n) {
      if (a[r] - a[l] <= h) {
        ok = true;
        break;
      }
      l++;
      r++;
    }
    cout << (ok == false ? "NO" : "YES") << endl;
  }
  return 0;
}