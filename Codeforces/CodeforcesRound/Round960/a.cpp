#include <bits/stdc++.h>

using namespace std;
int numTest; 
int a[100005]; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;   
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }                                             
    sort(a + 1, a + n + 1); 
    bool ok = false; 
    int cnt = 1; 
    for (int i = 2; i <= n; i++) {
      if (a[i] == a[i - 1]) {
        cnt++; 
      }
      else {
        if (cnt % 2 == 1) {
          ok = true; 
        }
        cnt = 1;
      }
    }
    if (cnt % 2 == 1) {
      ok = true; 
    }
    cout << (ok == true ? "YES" : "NO") << endl;
  }
  return 0; 
}