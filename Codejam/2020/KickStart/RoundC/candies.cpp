#include <bits/stdc++.h>

using namespace std;
int numTest;
const int MAX_N = 200005;
long long IT[4 * MAX_N], ITsum[4 * MAX_N];
long long a[MAX_N];
int n, Q;

void build(int index, int L, int R) {
  if (L > R) {
    return;
  }
  if (L == R) {
    ITsum[index] = 1LL * (L % 2 == 0 ? -1 : 1) * a[L];
    IT[index] = 1LL * (L % 2 == 0 ? -1 : 1) * L * a[L];
    return;
  }
  int mid = (L + R) >> 1;
  build(2 * index, L, mid);
  build(2 * index + 1, mid + 1, R);
  ITsum[index] = ITsum[2 * index] + ITsum[2 * index + 1];
  IT[index] = IT[2 * index] + IT[2 * index + 1];
}

void update(int index, int L, int R, int l, int r, long long value) {
  if (l <= L && R <= r) {
    IT[index] = (long long) L * value;
    ITsum[index] = value;
    return;
  }
  if (l > R || L > r) {
    return;
  }
  int mid = (L + R) >> 1;
  update(2 * index, L, mid, l, r, value);
  update(2 * index + 1, mid + 1, R, l, r, value);
  IT[index] = IT[2 * index] + IT[2 * index + 1];
  ITsum[index] = ITsum[2 * index] + ITsum[2 * index + 1];
}

pair <long long, long long> get(int index, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    pair <long long, long long> ret = make_pair(IT[index], ITsum[index]);
    return ret;
  }
  if (l > R || L > r) {
    return make_pair(0LL, 0LL);
  }
  int mid = (L + R) >> 1;
  pair <long long, long long> pairLeft = get(2 * index, L, mid, l, r);
  pair <long long, long long> pairRight = get(2 * index + 1, mid + 1, R, l, r);
  pair <long long, long long> ret;
  ret.first = pairLeft.first + pairRight.first;
  ret.second = pairLeft.second + pairRight.second;
  return ret;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0LL;
    build(1, 1, n);
    for (int i = 1; i <= Q; i++) {
      char type;
      cin >> type;
      if (type == 'U') {
        int pos, x;
        cin >> pos >> x;
        long long value = 1LL * (pos % 2 == 0 ? -1 : 1) * x;
        update(1, 1, n, pos, pos, value);
      }
      else {
        int l, r;
        cin >> l >> r;
        pair <long long, long long> twoSum = get(1, 1, n, l, r);
        long long firstValue = twoSum.first;
        long long secondValue = twoSum.second;
        firstValue -= (long long) (l - 1) * secondValue;
        if (l % 2 == 0) {
          firstValue = -firstValue;
        }
        ans += firstValue;
      }
    }
    cout << ans << endl;
  }
  return 0;
}