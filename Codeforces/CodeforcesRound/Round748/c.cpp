#include <bits/stdc++.h> 

using namespace std;
int numTest;
int x[400005]; 
int n, k; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
      cin >> x[i];
    }
    sort(x + 1, x + n + 1); 
    int cat = 0;
    int ans = 0;  
    for (int i = n; i >= 1; i--) {
      if (cat < x[i]) {
        cat += k - x[i];
        ans++; 
      }  
      else {
        break;
      }
    }
    cout << ans << endl;
  }
  return 0; 
}