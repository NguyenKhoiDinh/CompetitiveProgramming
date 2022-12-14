#include <bits/stdc++.h> 

using namespace std;
int numTest;
int a[1005]; 
int n; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      bool check = true;
      for (int j = 2; j <= n; j++) {
        if (a[j] < a[j - 1]) {
          check = false;
          break;
        }
      }
      if (check == true) {
        cout << i - 1 << endl;
        break;
      }
      int res = 0;
      if (i % 2 == 1) {
        for (int j = 1; j <= n; j += 2) {
          if (j + 1 <= n && a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            res++;
          }
        }
      }
      else {
        for (int j = 2; j <= n; j += 2) {
          if (j + 1 <= n && a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            res++;
          }
        }
      }
      check = true;
      for (int j = 2; j <= n; j++) {
        if (a[j] < a[j - 1]) {
          check = false;
          break;
        }
      }
      if (check == true) {
        cout << i << endl;
        break;
      }
    }                   
  }
  return 0; 
}