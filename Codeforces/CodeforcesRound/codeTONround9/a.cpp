#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << 2 * i - 1 << ' ';
    }  
    cout << endl;
  }
  return 0; 
}