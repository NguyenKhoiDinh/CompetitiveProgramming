#include <bits/stdc++.h>

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, y;
    cin >> x >> y;
    int ans = (y + 1) / 2;
    int numbx = 15 * ans - 4 * y;
    x -= numbx;
    if (x > 0) {
      ans += (x + 14) / 15; 
    }
    cout << ans << endl; 
  }
  return 0; 
}