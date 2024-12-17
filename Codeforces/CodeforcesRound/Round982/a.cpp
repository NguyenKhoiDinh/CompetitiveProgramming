#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    int maxw = 0;
    int maxh = 0; 
    for (int i = 1; i <= n; i++) {
      int w, h;
      cin >> w >> h;
      maxw = max(maxw, w);
      maxh = max(maxh, h); 
    }  
    cout << 2 * (maxw + maxh) << endl;
  }
  return 0; 
}