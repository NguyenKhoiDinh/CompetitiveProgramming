#include <bits/stdc++.h>

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    int j = 0; 
    int d = 0; 
    for (int i = 1; i <= n; i++) {
      cout << i << " " << j + 1 << endl; 
      j += d;
      j %= n; 
      d++; 
    }  
    cout << endl;
  }
  return 0; 
}