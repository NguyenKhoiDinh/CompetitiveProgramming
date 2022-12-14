#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct segment {
  long long l, r;
  bool operator < (const segment &hs) const {
    return (r < hs.r || (r == hs.r && l < hs.l));
  }
};
map <long long, long long> dp;
vector <segment> save;
long long lim;
int n;

int findPos(long long val) {
  int l = 0;
  int r = n - 1;
  int res = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (save[mid].r < val) {
      res = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return res;
}

int main () {
  freopen("input.txt", "r", stdin);
  scanf("%lld %d", &lim, &n);
  for (int i = 1; i <= n; i++) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    save.push_back((segment) {l, r});
  }
  sort(save.begin(), save.end());
  long long res = -1;
  for (int i = 0; i < n; i++) {
    long long l = save[i].l;
    long long r = save[i].r;
    int pos = findPos(l);
    dp[r] = max(dp[r], (pos != -1 ? dp[save[pos].r] : 0) + save[i].r - save[i].l + 1);
    pos = findPos(r);
    if (pos != -1) {
      dp[r] = max(dp[r], dp[save[pos].r]);
    }
    res = max(res, dp[r]);
  }
  cout << lim - res;
  return 0;
}