#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  //freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<ll> a(n);

  for(int i = 0; i < n; ++i) {
    string s; cin >> s;
    a[i] = stoll(s.substr(2));
  }

  vector<ll> ans(n);

  for(int r = 1; r <= 10000; ++r) {
    for(int d0 = -1; d0 <= 1; ++d0) {
      __int128 p = (__int128) r * (ll)1e12;
      __int128 q = a[0] + d0;
      
      bool array_ok = true;
      for(int i = 0; i < n; ++i) {
        bool i_ok = false;
        for(int di = -1; di <= 1; ++di) {
          __int128 x = a[i] + di;
          ll Ai = (p * x) / q;
          if (Ai % (ll)1e12 <= (ll)1e6 || (Ai + (ll)1e6) % (ll)1e12 <= (ll)1e6) {
            ans[i] = (Ai + (ll)1e6) / (ll)1e12;
            i_ok = true;
            break;
          }
        }
        if (!i_ok) {
          array_ok = false;
          break;
        }
      }

      if (array_ok) {
        for(int i = 0; i < n; ++i) {
          cout << ans[i] << endl;
        }
        return 0;
      }
    }
  }



  return 0;
}