#include <bits/stdc++.h> 

using namespace std;
int numTest;
int a[3]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 3; i++) {
      int maxi = -1;
      for (int j = 0; j < 3; j++) {
        if (j != i) {
          maxi = max(maxi, a[j]); 
        }  
      }
      if (a[i] > maxi) {
        cout << 0 << ' ';
      }
      else {
        cout << maxi + 1 - a[i] << ' ';
      }
    }   
    cout << endl;
  }
  return 0; 
}