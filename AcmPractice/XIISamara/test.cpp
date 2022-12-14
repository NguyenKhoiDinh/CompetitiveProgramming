#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n;
ll a[N], b[N], c[N], maxx[N];
ll d[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    maxx[i] = max({a[i], b[i], c[i]});
    d[i] = a[i] + b[i] + c[i] - maxx[i];
  }
  sort(d + 1, d + 1 + n);
  for (int i = 1; i <= n; ++i) {
    int pos = upper_bound(d + 1, d + 1 + n, a[i] + b[i] + c[i] - 2) - d;
    pos--;
    if (maxx[i] >= 2) pos--;
    if (i != 1) cout << " ";
    cout << pos;
  }
  cout << "\n";
  return 0;
}