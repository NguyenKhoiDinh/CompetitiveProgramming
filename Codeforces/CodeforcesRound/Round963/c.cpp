#include <bits/stdc++.h>

using namespace std;
int a[200005];

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }  
    sort(a + 1, a + n + 1); 
    int l = a[n];
    int r = a[n] + k - 1; 
    vector <pair <int, int> > save; 
    bool ok = true; 
    for (int i = 1; i < n; i++) {
      int numb = (l - a[i]) / k; 
      if (((l - a[i]) / k) % 2 != 0) {
        numb++;  
      }
      int li = a[i] + numb * k; 
      int ri = a[i] + numb * k + k - 1; 
      if (li > r || l > ri) {
        ok = false;
        break; 
      } 
      else {
        save.push_back(make_pair(max(l, li), min(r, ri)));
      }
    }
    if (ok == false) {
      cout << -1 << endl;
      continue; 
    }
    if (save.empty() == false) {
      int minR = save[0].second; 
      for (int i = 1; i < (int) save.size(); i++) {
        minR = min(minR, save[i].second); 
      }
      for (int i = 0; i < (int) save.size(); i++) {
        if (save[i].first > minR) {
          ok = false; 
          break; 
        }
      }
    } 
    if (ok == false) {
      cout << -1 << endl;
      continue;
    }
    int ans = l; 
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, save[i].first); 
    }
    cout << ans << endl;
  }
  return 0; 
}