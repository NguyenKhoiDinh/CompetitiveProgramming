#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int X, Y, K;
    cin >> X >> Y >> K;
    cout << 0 << ' ' << 0 << ' ' << min(X, Y) << ' ' << min(X, Y) << endl;
    cout << 0 << ' ' << min(X, Y) << ' ' << min(X, Y) << ' ' << 0 << endl;   
  }
  return 0; 
}