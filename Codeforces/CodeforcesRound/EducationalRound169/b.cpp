#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l2 > r1) {
      cout << 1; 
    } 
    else if (l1 > r2) {
      cout << 1; 
    }
    else if (l1 <= l2 && r2 <= r1) {
      int numb = r2 - l2 + 2; 
      if (l1 == l2) {
        numb--;
      }
      if (r1 == r2) {
        numb--; 
      }
      cout << numb; 
    }
    else if (l2 <= l1 && r1 <= r2) {
      int numb = r1 - l1 + 2; 
      if (l1 == l2) {
        numb--; 
      }
      if (r1 == r2) {
        numb--; 
      }
      cout << numb;
    }
    else {
      int maxL = max(l1, l2);
      int minR = min(r1, r2); 
      int numb = minR - maxL + 2; 
      cout << numb; 
    }
    cout << endl;
  }
  return 0; 
}