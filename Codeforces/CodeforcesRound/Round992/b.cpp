#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    if (n <= 2) {
      cout << n << endl; 
      continue; 
    }  
    int ans = 1;
    int p = 1;
    while (p < n) {
      ans++;
      p = p * 2 + 2;     
    } 
    cout << ans << endl;
  }
  return 0; 
}



                        
