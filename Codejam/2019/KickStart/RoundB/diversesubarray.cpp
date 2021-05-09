#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
int n, S; 
int a[MAX_N];
queue <int> pos[MAX_N];
int it[4 * MAX_N];
int itMax[4 * MAX_N];

void lazyUpdate(int index) {
  for (int i = 2 * index; i <= 2 * index + 1; i++) {
    it[i] += it[index]; 
    itMax[i] += it[index]; 
  }
  it[index] = 0; 
}

void update(int index, int L, int R, int l, int r, int val) {
  if (l > R || L > r) {
    return; 
  }
  if (l <= L && R <= r) {
    it[index] += val;
    itMax[index] += val;
    return; 
  }
  lazyUpdate(index);
  int mid = (L + R) >> 1; 
  update(2 * index, L, mid, l, r, val);
  update(2 * index + 1, mid + 1, R, l, r, val);  
  itMax[index] = max(itMax[2 * index], itMax[2 * index + 1]);
}

int get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return -1; 
  }
  if (l <= L && R <= r) {
    return itMax[index]; 
  }
  lazyUpdate(index);
  int mid = (L + R) >> 1;
  int v1 = get(2 * index, L, mid, l, r); 
  int v2 = get(2 * index + 1, mid + 1, R, l, r);
  return max(v1, v2);  
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> S; 
    int maxA = -1; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      maxA = max(maxA, a[i]); 
    }
    for (int i = 1; i <= maxA; i++) {
      while (!pos[i].empty()) {
        pos[i].pop(); 
      }
    }
    for (int i = 1; i <= n; i++) {
      pos[a[i]].push(i);
    }
    memset(it, 0, sizeof(it));
    memset(itMax, 0, sizeof(itMax));
    for (int i = 1; i <= maxA; i++) {
      for (int j = 1; j <= S; j++) {
        if (!pos[i].empty()) {
          int p = pos[i].front();
          pos[i].pop();
          update(1, 1, n, p, p, 1);
        }
        else {
          break; 
        }
      }
      if (!pos[i].empty()) {
        int p = pos[i].front(); 
        update(1, 1, n, p, p, -S);
      }
    }
    int ans = -1; 
    for (int l = 1; l <= n; l++) {
      int maxValue = get(1, 1, n, l, n); 
      ans = max(ans, maxValue);
      if (!pos[a[l]].empty()) {
        int p = pos[a[l]].front();
        pos[a[l]].pop(); 
        update(1, 1, n, p, p, S + 1);
      }
      if (!pos[a[l]].empty()) {
        int p = pos[a[l]].front(); 
        update(1, 1, n, p, p, -S);
      }
    }
    cout << ans << endl;
  }
  return 0; 
}