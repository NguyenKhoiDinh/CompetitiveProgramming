#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 500005; 
struct element {
  int maxValue, minValue;
};
element it[4 * MAX_N];
int n, query; 
int a[MAX_N];

void update(int index, int L, int R) {
  if (L == R) {
    it[index].maxValue = a[L];
    it[index].minValue = a[L];
    return; 
  }
  int mid = (L + R) >> 1; 
  update(2 * index, L, mid); 
  update(2 * index + 1, mid + 1, R);
  it[index].maxValue = max(it[2 * index].maxValue, it[2 * index + 1].maxValue);
  it[index].minValue = min(it[2 * index].minValue, it[2 * index + 1].minValue);
}

pair <int, int> get(int index, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    return make_pair(it[index].maxValue, it[index].minValue);
  }
  if (l > R || L > r) {
    return make_pair(-1, 1000005);
  }
  int mid = (L + R) >> 1; 
  pair <int, int> v1 = get(2 * index, L, mid, l, r); 
  pair <int, int> v2 = get(2 * index + 1, mid + 1, R, l, r);
  pair <int, int> res;
  res.first = max(v1.first, v2.first); 
  res.second = min(v1.second, v2.second); 
  return res; 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> query; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  update(1, 1, n);
  for (int i = 1; i <= query; i++) {
    int l, r;
    cin >> l >> r; 
    pair <int, int> res = get(1, 1, n, l, r);
    cout << res.first - res.second << endl;
  }
  return 0; 
}