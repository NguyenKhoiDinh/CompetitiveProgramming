#include <bits/stdc++.h> 

using namespace std;
int n, k, numTest;
int a[1005];
int cnt[1005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt)); 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]]++; 
    } 
    bool ok = false; 
    int numb = n; 
    for (int x = 1001; x >= 0; x--) {
      numb -= cnt[x];
      if (numb == k) {
        cout << "YES" << endl;
        ok = true;  
        break; 
      }  
    } 
    if (ok == false) {
      cout << "NO" << endl; 
    }
  }
  return 0; 
}