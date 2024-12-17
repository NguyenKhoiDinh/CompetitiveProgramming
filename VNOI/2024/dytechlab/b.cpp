#include <bits/stdc++.h> 

using namespace std;
int numTest;
map <int, int> cnt; 
int n, k; 
int l[1000005];

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cnt.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> l[i];
      cnt[l[i]]++; 
    }    
    sort(l + 1, l + n + 1); 
    int total = 0; 
    int prev = -1; 
    int ans = n + 1; 
    for (int i = n; i >= 1; i--) {
      if (l[i] != prev) {
        if (cnt[l[i]] + total >= k) {
          ans = min(ans, max(0, k - cnt[l[i]])); 
        }
        total += cnt[l[i]];
        prev = l[i];  
      }  
    }
    cout << ans << endl; 
  }
  return 0; 
}