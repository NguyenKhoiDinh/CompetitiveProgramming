#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[55]; 
int suffix[55]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    suffix[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      suffix[i] = suffix[i + 1] + a[i]; 
    }    
    set <int> S; 
    for (int i = n; i >= 1; i--) {
      S.insert(suffix[i]); 
    }
    set <int>::iterator it = S.upper_bound(k);
    it--;
    cout << k - *it << endl; 
  }
  return 0; 
}