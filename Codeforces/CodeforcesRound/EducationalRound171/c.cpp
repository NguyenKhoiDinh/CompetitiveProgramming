#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 1LL * n * (n + 1) / 2;
    int need = 0;
    for (int i = n; i >= 1; i--) {
      if (s[i - 1] == '1' && need + 2 <= i) {
        ans -= i;
        need++; 
      }
      else {
        need = max(0, need - 1); 
      }
    }  
    cout << ans << endl;
  }
  return 0; 
}                    
