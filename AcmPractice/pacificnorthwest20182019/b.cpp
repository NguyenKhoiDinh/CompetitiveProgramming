#include <bits/stdc++.h> 

using namespace std;
const int LIM = 10000007;
long long a, b, c, d;
int mobius[LIM];

void init() {
  mobius[1] = 1;
  for (int i = 1; i < LIM; i++) {
    if (mobius[i] == 0) {
      continue;
    }
    for (int j = 2 * i; j < LIM; j += i) {
      mobius[j] -= mobius[i];
    }
  } 
}

int main () {
  //freopen("input.txt", "r", stdin);
  cin >> a >> b >> c >> d;
  a--;
  c--;
  init();
  long long ans = 0LL;
  for (int i = 1; i <= max(b, d); i++) {
    ans += 1LL * ((b / i) - (a / i)) * ((d / i) - (c / i)) * mobius[i];
  }
  cout << ans;
  return 0;
}