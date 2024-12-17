#include <bits/stdc++.h>

using namespace std;
int n;
int a[100005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }     
    sort(a + 1, a + n + 1); 
    int l = 1;
    int r = n; 
    bool flag = true; 
    while (l < r) {
      if (flag == true) {
        l++; 
      }  
      else {
        r--; 
      }
      flag = !flag; 
    }
    cout << a[l] << endl;
  }
  return 0; 
}