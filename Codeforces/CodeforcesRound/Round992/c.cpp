#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    long long k;
    cin >> n >> k;  
    long long total = 1LL;
    for (int i = 1; i < n; i++) {
      total *= 2LL;
      total = min(total, k);  
    }
    if (total < k) {
      cout << -1 << endl; 
      continue; 
    }
    vector <int> ans(n);
    int pl = 0;
    int pr = n - 1; 
    for (int i = 1; i <= n; i++) {
      if (n - i - 1 >= 60) {
        ans[pl] = i;
        pl++;
        continue;    
      }
      long long ways = 1LL; 
      for (int j = 1; j <= n - i - 1; j++) {
        ways *= 2LL; 
      }
      if (ways < k) {
        ans[pr] = i;
        pr--; 
        k -= ways; 
      }
      else {
        ans[pl] = i;
        pl++; 
      }
    }     
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  return 0; 
}

    

