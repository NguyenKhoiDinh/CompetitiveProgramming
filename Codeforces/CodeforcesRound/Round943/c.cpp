#include <bits/stdc++.h>

using namespace std;
int numTest; 
int n;
int x[505]; 
int a[505];

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 2; i <= n; i++) {
      cin >> x[i]; 
    }
    a[1] = 501; 
    for (int i = 2; i <= n; i++) {
      a[i] = a[i - 1] + x[i]; 
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' '; 
    }
    cout << endl;
  }
  return 0; 
}