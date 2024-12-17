#include <bits/stdc++.h>

using namespace std;
int a[2005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;   
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    int ans = n; 
    for (int i = 1; i <= n; i++) {
      int numb = 0; 
      for (int j = i + 1; j <= n; j++) {
        if (a[j] <= a[i]) {
          numb++; 
        }
      }
      ans = min(ans, n - (numb + 1));
    }
    cout << ans << endl; 
  }
  return 0; 
}