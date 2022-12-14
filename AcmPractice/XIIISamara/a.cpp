#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 500005;
long long a[MAX_N];
int n;
int query;

int main () {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  long long sum = 0LL;
  for (int i = 1; i <= n; i += 2) {
    sum += (n % 2 == 0 ? -1LL : 1LL) * a[i];
  }
  for (int i = 2; i <= n; i += 2) {
    sum += (n % 2 == 0 ? 1LL : -1LL) * a[i];
  }
  scanf("%d", &query);
  for (int i = 1; i <= query; i++) {
    int l, r;
    long long value;
    scanf("%d %d %lld", &l, &r, &value);
    int len = r - l + 1;
    if (len % 2 == 0) {
      printf("%lld\n", sum);
    }
    else {
      long long addValue = 0LL;
      if (n % 2 == 0) {
        addValue = (l % 2 == 0 ? value : -value);
      }
      else {
        addValue = (l % 2 == 0 ? -value : value);
      }
      printf("%lld\n", sum + addValue);
      sum += addValue;
    }
  }
  return 0;
}