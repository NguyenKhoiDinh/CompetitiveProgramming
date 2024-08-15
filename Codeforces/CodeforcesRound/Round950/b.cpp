#include <bits/stdc++.h>

using namespace std;
int numTest; 
int a[105]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, f, k;
    cin >> n >> f >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }  
    int value = a[f]; 
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    bool canRemove = false; 
    for (int i = 1; i <= k; i++) {
      if (a[i] == value) {
        canRemove = true; 
      } 
    }
    bool canNotRemove = false;
    for (int i = k + 1; i <= n; i++) {
      if (a[i] == value) {
        canNotRemove = true; 
      }
    } 
    if (canRemove == true && canNotRemove == true) {
      cout << "MAYBE";
    }
    else if (canRemove == true) {
      cout << "YES"; 
    }
    else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0; 
}