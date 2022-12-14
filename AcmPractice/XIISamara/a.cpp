#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 500005;
int n;
int a[MAX_N];
int ans[MAX_N], cnt[MAX_N];

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 0;
  int r = 1;
  while (l < n) {
    while (r <= n && !(a[r] > 0 && cnt[a[r]] > 0)) {
      r++;
      if (a[r - 1] < 0) {
        cnt[-a[r - 1]]++;
      }
    }
    cout << r - l - 1 << ' ';
    l++;                            
    if (a[l] < 0) {
      cnt[-a[l]]--;
    }
  }                 
  return 0; 
}