#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005; 
int numTest;
int a[MAX_N];
int n; 

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
    int diff = a[2] - a[1]; 
    int len = 2; 
    int ans = len; 
    for (int i = 3; i <= n; i++) {
      if (a[i] - a[i - 1] == diff) {
        len++; 
        ans = max(ans, len); 
      }
      else {
        len = 2; 
        diff = a[i] - a[i - 1];
      }
    }
    cout << ans << endl;
  }
  return 0;
}