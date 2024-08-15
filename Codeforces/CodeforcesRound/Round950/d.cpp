#include <bits/stdc++.h>

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    vector <int> a;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }  
    vector <int> b; 
    for (int i = 0; i < n - 1; i++) {
      b.push_back(__gcd(a[i], a[i + 1])); 
    }
    vector <bool> okLeft(n - 1, false), okRight(n - 1, false);
    okLeft[0] = true;
    for (int i = 1; i < n - 1; i++) {
      if (b[i] >= b[i - 1]) {
        okLeft[i] = true; 
      }
      else {
        break; 
      }
    }
    okRight[n - 2] = true;
    for (int i = n - 3; i >= 0; i--) {
      if (b[i] <= b[i + 1]) {
        okRight[i] = true; 
      }
      else {
        break; 
      }
    } 
    //a = [a0, a1, a2, a3, a4, a5, a6] 
    bool ok = false; 
    for (int i = 0; i < n; i++) {
      if (i == 0 && okRight[1] == true) {
        ok = true;
        break; 
      }
      if (i == n - 1 && okLeft[n - 3] == true) {
        ok = true;
        break; 
      }
      int gcdMid = __gcd(a[i - 1], a[i + 1]);
      int gcdLeft = (i - 1 == 0 ? -1 : __gcd(a[i - 2], a[i - 1]));
      int gcdRight = (i + 1 == n - 1 ? 1000000007 : __gcd(a[i + 1], a[i + 2]));
      if (gcdLeft <= gcdMid && gcdMid <= gcdRight && (i - 1 == 0 || (i > 1 && okLeft[i - 2] == true)) && (i + 1 == n - 1 || (i + 1 < n - 1 && okRight[i + 1] == true))) {
        ok = true;
        break; 
      } 
    } 
    cout << (ok == true ? "YES" : "NO") << endl;   
  }
  return 0; 
}