#include <bits/stdc++.h>

using namespace std;
int a[44];

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }    
    if (n > 2) {
      cout << "NO"; 
    }
    else {
      cout << (a[2] - a[1] > 1 ? "YES" : "NO"); 
    }
    cout << endl;
  }
  return 0; 
}