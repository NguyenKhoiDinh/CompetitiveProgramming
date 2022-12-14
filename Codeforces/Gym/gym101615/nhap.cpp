#include <iostream
#include <algorithm>
#include <math.h

using namespace std;

const int MAX_N = 200010;
const int MAX_T = 1000010;

const long long inf = 1LL << 60;

int len[MAX_N], ptr[MAX_N], base[MAX_N], which[MAX_T], type[MAX_T], f[MAX_T], t[MAX_T];
long long A[MAX_N], B[MAX_N], C[MAX_N];
bool reached[MAX_N];

void addLine(int index, long long a, long long b) {
  while (len[index] >= 2 + base[idx - 1] && (B[len[index] - 2] - B[len[index] - 1]) * (a - A[len[index] - 1]) >= (B[len[index] - 1] - b) * (A[len[index] - 1] - A[len[index] - 2])) {
    --len[idx];
  }
  A[len[index]] = a; B[len[index]] = b;
  ptr[index] = min(ptr[index], len[index]++);
}

long long minValue(int index, long long x) {
  if (len[index] == 0) return inf;
  int p;
  while ((p = ptr[index]) + 1 < len[index] && A[p + 1] * x + B[p + 1] <= A[p] * x + B[p]) {
    ++ptr[index];
  }
  return A[p] * x + B[p];
}

int main() {
  int n, m;
  cin >> n >> m;
  base[1]++;
  for (int i = 1; i <= m; i++) {
    int a, b, s, e;
    cin >> a >> b >> s >> e;
    which[s] = which[e] = i;
    f[s] = a;
    t[e] = b;
    type[s] = 1;
    type[e] = -1;
    base[b]++;
    C[i] = inf;
  }
  for (int i = 1; i <= n; i++) {
    base[i] += (len[i] = ptr[i] = base[i - 1]);
  }
  addLine(1, 0, 0);
  reached[1] = true;
  long long ans = inf;
  for (int i = 0; i < MAX_T; i++) {
    if (which[i] == false) {
      continue;
    }
    if (type[i] == 1) {
      if (reached[f[i]] == true) {
        C[which[i]] = 1LL * i * i + minValue(f[i], i);
      }
    }
    else if (C[which[i]] < inf) {
      if (t[i] == n) {
        ans = min(ans, C[which[i]]);
        addLine(t[i], -1 * i, C[which[i]] + 1LL * i * i);
        reached[t[i]] = true;
      }
    }
  }
  cout << ans;
  return 0;
}