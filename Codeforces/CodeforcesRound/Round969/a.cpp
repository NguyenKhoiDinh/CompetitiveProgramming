#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = (l % 2 == 0 ? l + 1 : l); i + 2 <= r; i += 4) {
      ans++;   
    }    
    cout << ans << endl;
  }
  return 0; 
}

                                                                                            
