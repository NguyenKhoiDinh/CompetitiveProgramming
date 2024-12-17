#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[100005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    int maxValue = -1; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      maxValue = max(maxValue, a[i]); 
    }
    for (int i = 1; i <= m; i++) {
      char type;
      int l, r; 
      cin >> type >> l >> r; 
      if (l <= maxValue && maxValue <= r) {
        if (type == '+') {
          maxValue++; 
        }
        else {
          maxValue--; 
        }
      }
      cout << maxValue << ' '; 
    }
    cout << endl; 
  }
  return 0; 
}