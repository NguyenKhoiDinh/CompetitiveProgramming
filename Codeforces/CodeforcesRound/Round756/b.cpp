#include <bits/stdc++.h> 

using namespace std;
int numTest;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a, b); 
    } 
    int ans = 0; 
    ans = (a - b) / 2; 
    ans = min(ans, b);
    ans = min(ans, a / 3); 
    a -= ans * 3;
    b -= ans; 
    ans += min(a, b) / 2; 
    cout << ans << endl;
  }
  return 0; 
}