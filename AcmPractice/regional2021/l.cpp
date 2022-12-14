#include <bits/stdc++.h> 

using namespace std;
int numTest; 
int n; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n; 
    string ans = ""; 
    while (n > 1) {
      if (n % 2 == 0) {
        ans += 'L'; 
      }
      else {
        ans += 'R'; 
      }
      n /= 2; 
    }
    reverse(ans.begin(), ans.end()); 
    cout << ans << endl;
  }
  return 0; 
}