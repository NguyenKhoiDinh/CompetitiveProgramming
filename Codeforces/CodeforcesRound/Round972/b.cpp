#include <bits/stdc++.h>

using namespace std;
int n, m, q; 
int a[100005], b[100005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m >> q; 
    for (int i = 1; i <= m; i++) {
      cin >> b[i]; 
    }
    sort(b + 1, b + m + 1); 
    for (int i = 1; i <= q; i++) {
      cin >> a[i];
      int lo = 1;
      int hi = m;
      int left = -1, right = -1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (b[mid] < a[i]) {
          left = mid; 
          lo = mid + 1; 
        }
        else {
          hi = mid - 1; 
        }
      } 
      lo = 1;
      hi = m; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (b[mid] > a[i]) {
          right = mid; 
          hi = mid - 1; 
        }
        else {
          lo = mid + 1; 
        }
      }
      if (left == -1) {
        cout << b[right] - 1 << endl; 
      }
      else if (right == -1) {
        cout << n - b[left] << endl; 
      }
      else {
        cout << (b[right] - b[left]) / 2 << endl;
      }
    }
  }
  return 0; 
}