#include <bits/stdc++.h>
using namespace std;
int T, n; 
vector <int> a, Left, Right, Log2; 
stack <int> store; 
vector <vector <int> > sparse; 

void init() {
  Log2.resize(n + 1); 
  for (int k = 0; (1 << k) <= n; k++) {
    Log2[1 << k] = k; 
  }
  for (int i = 1; i <= n; i++) {
    if (Log2[i] == 0) {
      Log2[i] = Log2[i - 1]; 
    }
  }
  sparse.resize(n + 1); 
  for (int i = 1; i <= n; i++) {
    sparse[i].resize(22); 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 21; j++) {
      sparse[i][j] = -1; 
    }
  }
  for (int i = 1; i <= n; i++) {
    sparse[i][0] = a[i]; 
  }
  for (int j = 1; j <= 21; j++) {
    for (int i = 1; i <= n; i++) {
      if ((i - (1 << (j - 1))) > 0) {
        sparse[i][j] = max(sparse[i][j - 1], sparse[i - (1 << (j - 1))][j - 1]); 
      }
    }
  }
} 

int rmq(int l, int r) {
  int len = Log2[r - l + 1];
  return max(sparse[r][len], sparse[l + (1 << len) - 1][len]); 
}

int main () {
  //freopen("CHUNGKHOAN.INP", "r", stdin);
  //freopen("CHUNGKHOAN.OUT", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin >> T >> n; 
  a.resize(n + 1);
  Left.resize(n + 3);
  Right.resize(n + 3);
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  init(); 
  store.push(0); 
  for (int i = 1; i <= n; i++) {
    while (a[store.top()] >= a[i]) {
      store.pop();   
    }
    Left[i] = store.top();
    store.push(i); 
  }
  while (store.empty() == true) {
    store.pop(); 
  }
  store.push(n + 1); 
  for (int i = n; i >= 1; i--) {
    while (a[store.top()] >= a[i]) {
      store.pop(); 
    }
    Right[i] = store.top();
    store.push(i);  
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = Left[i] + 1; 
    int r = Right[i] - 1; 
    int minLeft = -1, maxRight = -1; 
    int lo = l; 
    int hi = i; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (rmq(mid, i) - a[i] <= T) {
        minLeft = mid; 
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
    lo = i; 
    hi = r; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (rmq(i, mid) - a[i] <= T) {
        maxRight = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    ans = max(ans, maxRight - minLeft + 1); 
  }
  cout << ans; 
  return 0; 
}