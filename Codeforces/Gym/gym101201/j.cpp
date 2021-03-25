#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX_N = 200005;
const long long inf = 1e18 + 5;
long long it[4 * MAX_N];
long long a[MAX_N];
int n, query;

void buildTree(int index, int l, int r) {
  if (l > r) {
    return;
  }
  if (l == r) {
    it[index] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  buildTree(2 * index, l, mid);
  buildTree(2 * index + 1, mid + 1, r);
  it[index] = min(it[2 * index], it[2 * index + 1]);
}

long long get(int index, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return it[index];
  }
  if (l > R || r < L) {
    return inf;
  }
  int mid = (l + r) >> 1;
  long long v1 = get(2 * index, l, mid, L, R);
  long long v2 = get(2 * index + 1, mid + 1, r, L, R);
  return min(v1, v2);
}

int main () {
  scanf("%d %d", &n, &query);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  buildTree(1, 1, n);
  for (int qq = 1; qq <= query; qq++) {
    long long val;
    int l, r;
    scanf("%lld %d %d", &val, &l, &r);
    while (true) {
      int left = l, right = r, pos = -1;
      long long valRange;
      while (left <= right) {
        int mid = (left + right) >> 1;
        long long tmp = get(1, 1, n, l, mid);
        if (tmp <= val) {
          valRange = tmp;
          pos = mid;
          right = mid - 1;
        }
        else {
          left = mid + 1;
        }
      }
      if (pos != -1) {
        val %= valRange;
        l = pos + 1;
      }
      else {
        break;
      }
    }
    printf("%lld\n", val);
  }
  return 0;
}