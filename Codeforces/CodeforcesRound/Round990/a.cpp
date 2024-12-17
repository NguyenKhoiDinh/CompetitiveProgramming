#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n; 
    cin >> n;
    int numb = 0; 
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      numb += x;
      int v = 1;
      while (v * v < numb) {
        v += 2; 
      } 
      if (v * v == numb) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0; 
}