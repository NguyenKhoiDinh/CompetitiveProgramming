#include <bits/stdc++.h>

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x;
    cin >> x;
    int ans = 0;
    int maxi = 0; 
    for (int y = 1; y < x; y++) {
      if (maxi < __gcd(x, y) + y) {
        maxi = __gcd(x, y) + y;
        ans = y;
      } 
    }   
    cout << ans << endl;
  }
  return 0; 
}