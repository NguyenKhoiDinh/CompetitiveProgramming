#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD = 1000000007;
const int MAX_N = 100005;
 
struct node {
  long long val;
  int cnt[15];
  node operator * (const node &hs) const {
    node res;
    res.val = (val * hs.val) % MOD;
    for (int i = 2; i <= 13; i++) {
      res.cnt[i] = cnt[i] + hs.cnt[i];
    }
    return res;
  }
};
 
long long a[MAX_N];
node b[MAX_N];
int n, k, query;
node IT[4 * MAX_N];
int d[MAX_N];
int p = 0;
int pos[MAX_N];
vector <int> adj[MAX_N];
vector <int> save;
long long sum[MAX_N];
 
void DFS(int x, int father) {
  save.push_back(x);
  int sz = save.size();
  pos[x] = sz - 1;
  for (int i = 0; i < (int) adj[x].size(); i++) {
    int t = adj[x][i]; 
    if (t == father) {
      continue;
    }
    DFS(t, x);
    d[x] += d[t];
  }
}
 
void buildIT(int index, int l, int r) {
  if (l == r) {
    IT[index] = b[l];
    return;
  }
  if (l > r) {
    return;
  }
  int mid = (l + r) / 2;
  buildIT(2 * index, l, mid);
  buildIT(2 * index + 1, mid + 1, r);
  IT[index] = IT[2 * index] * IT[2 * index + 1];
}
 
void updateIT(int index, int l, int r, int L, int R, node val) {
  if (l > r) {
    return;
  }
  if (l > R || r < L) {
    return;
  }
  if (l == r) {
    IT[index] = IT[index] * val; 
    return; 
  }
  if (l <= L && R <= r) {
    IT[index] = IT[index] * val;
  }
  int mid = (l + r) / 2;
  updateIT(2 * index, l, mid, L, R, val);
  updateIT(2 * index + 1, mid + 1, r, L, R, val);
}
 
node Query(int index, int l , int r , int L , int R) {
  node T;
  T.val = 1LL;
  for (int i = 0; i < 15; i++) {
    T.cnt[i] = 0;
  }
  if (l > R || r < L) {
    return T;
  }
  if (L <= l && r <= R) {
    return IT[index];
  }
  int mid = (l + r) / 2;
  node T1 = Query(2 * index, l, mid, L, R);
  node T2 = Query(2 * index + 1, mid + 1, r, L, R);
  T = T1 * T2;
  return T;
}
 
int main () {
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  for (int i = 0; i < n; i++) {
    d[i] = 1;
  }
  DFS(0, -1);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    b[i].val = a[save[i]];
    long long t = b[i].val;
    for (int x = 2; x <= 13; x++) {
      while (!(t % x)) {
        b[i].cnt[x]++;
        t /= x;
      }
    }
  }
  buildIT(1, 0, n - 1);
  scanf("%d", &query);
  while (query--) {
    char s[7];
    scanf("%s", s);
    if (s[0] == 'R') {
      int r;
      scanf("%d", &r);
      node res = Query(1, 0, n - 1, pos[r], pos[r] + d[r] - 1); 
      printf("%lld ", res.val);
      long long mul = 1LL;
      for (int i = 2; i <= 13; i++) {
        (mul *= (long long) (res.cnt[i] + 1)) %= MOD;
      }
      printf("%lld\n", mul);
    }
    else {
      int r;
      long long val;
      scanf("%d %lld", &r, &val);
      node T;
      T.val = val;
      long long t = T.val; 
      for (int i = 0; i < 15; i++) {
        T.cnt[i] = 0;
      }
      for (int x = 2; x <= 13; x++) {
        while (!(t % x)) {
          T.cnt[x]++;
          t /= x;
        }
      }
      updateIT(1, 0, n - 1, pos[r], pos[r], T);
    }
  }
  return 0;
}