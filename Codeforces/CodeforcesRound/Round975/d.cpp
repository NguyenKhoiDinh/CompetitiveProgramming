#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007; 
int n;
int p[200005]; 
int range[200005]; 
int it[8 * 200005]; 
int prefix[200005], suffix[200005]; 
void update(int index, int L, int R, int position, int value) {
  if (L > position || R < position) {
    return; 
  }
  if (L == R) {
    it[index] = value; 
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value); 
  update(2 * index + 1, mid + 1, R, position, value); 
  it[index] = min(it[2 * index], it[2 * index + 1]); 
}
int get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return inf; 
  }
  if (l <= L && R <= r) {                                            
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  int getLeft = get(2 * index, L, mid, l, r); 
  int getRight = get(2 * index + 1, mid + 1, R, l, r); 
  return min(getLeft, getRight); 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> p[i]; 
    }
    for (int i = 1; i <= n; i++) {
      range[i] = 0; 
      prefix[i] = inf; 
      suffix[i] = inf; 
    }
    suffix[n + 1] = inf; 
    prefix[0] = inf;
    for (int i = 0; i <= 8 * n; i++) {
      it[i] = inf; 
    }
    for (int i = 1; i < n; i++) {
      update(1, 1, 2 * n, p[i] + i, i);
      int right = i + 1;
      int lo = 1;
      int hi = i;
      int maxLeft = -1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (1 - mid > p[right] - right) {
          maxLeft = mid;
          lo = mid + 1;  
        }
        else {
          hi = mid - 1; 
        }
      }
      if (maxLeft == -1) {
        continue; 
      }                       
      int minLeft = (2 <= right ? get(1, 1, 2 * n, 2, right) : inf);
      if (minLeft <= maxLeft) {
        range[minLeft]++;
        range[right + 1]--; 
      }
    }
    for (int i = 1; i <= n; i++) {
      range[i] += range[i - 1]; 
    }
    for (int i = 1; i <= n; i++) {
      prefix[i] = min(prefix[i - 1], p[i] + i); 
    }
    for (int i = n; i >= 1; i--) {
      suffix[i] = min(suffix[i + 1], p[i] - i); 
    }
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      if (range[i] == 0 && prefix[i - 1] >= i + 1 && suffix[i + 1] >= 1 - i) {
        ans++; 
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}