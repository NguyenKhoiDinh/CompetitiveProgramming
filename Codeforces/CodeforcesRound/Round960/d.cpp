#include <bits/stdc++.h>

using namespace std;
int numTest; 
int f[200005]; 
int n;
int a[200005]; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    bool ok1 = false, ok2 = false;
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      if (ok1 == false && ok2 == false) {
        if (a[i] == 0) { 
          continue; 
        }
        ans++; 
        if (a[i] <= 2) {
          ok1 = true; 
        }
      }
      else if (ok1 == true) {
        ok1 = false; 
        if (a[i] <= 2) {
          continue; 
        }
        ans++; 
        if (a[i] <= 4) {
          ok2 = true; 
        }
      }
      else {
        ok2 = false; 
        if (a[i] == 0) {
          continue; 
        }
        ans++;
        if (a[i] <= 4) {
          ok1 = true; 
        } 
      }
    } 
    cout << ans << endl;
  }
  return 0; 
}