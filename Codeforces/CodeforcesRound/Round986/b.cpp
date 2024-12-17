#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n, b, c;
    cin >> n >> b >> c;
    if (b == 0) {
      if (c < n - 2) {
        cout << -1 << endl; 
      }
      else {
        if (c >= n) {
          cout << n << endl; 
        }
        else {
          cout << n - 1 << endl; 
        }
      }
    }
    else {
      if (c >= n) {
        cout << n << endl; 
        continue; 
      }
      long long lo = (n - c + b - 1) / b + 1; 
      cout << n - lo + 1 << endl; 
    }  
  }
  return 0; 
}