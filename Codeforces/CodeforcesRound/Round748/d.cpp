#include <bits/stdc++.h> 

using namespace std;
int numTest;
int n;
int a[45]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }  
    int ans = 1;
    for (int r = 1; r <= 1000004; r++) {
      int v = (1LL * a[1] + (1LL * abs(a[1]) * r)) % r; 
      bool check = true;
      for (int i = 2; i <= n; i++) {
        int mod = (1LL * a[i] + (1LL * abs(a[i]) * r)) % r;
        if (mod != v) {
          check = false;
          break;
        }  
      }
      if (check == true) {
        ans = r;
      }
    }
    cout << (ans == 1000004 ? -1 : ans) << endl;
  }
  return 0; 
}

                                
