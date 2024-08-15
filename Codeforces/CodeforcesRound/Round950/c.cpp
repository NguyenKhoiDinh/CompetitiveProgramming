#include <bits/stdc++.h>

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    vector <int> a, b; 
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    map <int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[b[i]]++; 
    }
    int m;
    cin >> m;
    vector <int> d(m);
    for (int i = 0; i < m; i++) {
      cin >> d[i]; 
    }
    bool check = false; 
    bool ok = true; 
    for (int i = m - 1; i >= 0; i--) {
      if (cnt.find(d[i]) != cnt.end() && cnt[d[i]] > 0) {
        cnt[d[i]]--; 
        check = true; 
      }
      else if (cnt.find(d[i]) != cnt.end()) {
        check = true;   
      }
      else if (check == true) {
        continue; 
      }
      else {
        ok = false;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (cnt[b[i]] > 0 && a[i] == b[i]) {
        cnt[b[i]]--; 
      }
    }
    for (int i = 0; i < n; i++) {
      if (cnt[b[i]] > 0) {
        ok = false;
        break;
      }
    }
    cout << (ok == true ? "YES" : "NO") << endl;
  }
  return 0; 
}