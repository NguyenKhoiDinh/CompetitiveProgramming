#include <bits/stdc++.h> 

using namespace std; 
long long IT[800020]; 
long long dp[200005]; 
long long h[200005], a[200005]; 
int n; 

long long get(int index, int L, int R, int l, int r) {
  if (r < L || l > R) {
    return -1; 
  }
  if (l <= L && R <= r) {
    return IT[index]; 
  }
  int mid = (L + R) >> 1; 
  long long v1 = get(2 * index, L, mid, l, r);
  long long v2 = get(2 * index + 1, mid + 1, R, l, r);
  return max(v1, v2); 
}

void lazy(int index, int L, int R, int l, int r, long long val) {
  if (r < L || l > R) {
    return; 
  }
  if (l <= L && R <= r) {
    IT[index] = val; 
    return; 
  }
  int mid = (L + R) >> 1; 
  lazy(2 * index, L, mid, l, r, val);
  lazy(2 * index + 1, mid + 1, R, l, r, val);
  IT[index] = max(IT[2 * index], IT[2 * index + 1]); 
}

int main () {
  cin >> n; 
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long res = -1;
  for (int i = 1; i <= n; i++) {
    long long v = get(1, 1, n, 1, h[i] - 1); 
    if (v != -1) {
      dp[i] = v + a[i]; 
    }
    else {
      dp[i] = a[i];
    }
    res = max(res, dp[i]); 
    lazy(1, 1, n, h[i], h[i], dp[i]); 
  }
  cout << res; 
  return 0; 
}