#include <bits/stdc++.h>

using namespace std;
int numTest; 
int n, numQueries; 
int a[200005];

int main () {
  ios_base::sync_with_stdio(false);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQueries; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    for (int query = 1; query <= numQueries; query++) {
      int type;
      cin >> type;
      if (type == 1) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        for (int i = l; i <= r; i++) {
          if (a[i] == x) {
            a[i] = y; 
          }
        }
      }
      else if (type == 2) {
        int p;
        cin >> p;
        cout << a[p] << endl; 
      }
      else {
        int l, r, x;
        cin >> l >> r >> x;
        int cnt = 0; 
        for (int i = l; i <= r; i++) {
          if (a[i] == x) {
            cnt++; 
          }
        }
        cout << cnt << endl; 
      }
    }
    long long sum = 0LL;
    for (int i = 1; i <= n; i++) {
      sum += a[i];
    }
    cout << sum << endl;
  }
  return 0; 
}