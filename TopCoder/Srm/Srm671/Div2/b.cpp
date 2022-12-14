#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 505;
map <int, int> cnt[MAX_N];

class BearDartsDiv2 {
  public:
  long long count(vector <int> w) {
    int n = (int) w.size();
    for (int i = n - 1; i >= 0; i--) {
      for (int x = 0; x <= 1000000; x++) {
        cnt[i] = cnt[i + 1];
      }
      cnt[i][w[i]]++;
    }
    long long res = 0LL;
    for (int i = 0; i < n - 3; i++) {
      for (int j = i + 1; j < n - 2; j++) {
        if (w[j] > 1000000 / w[i]) {
          continue;
        }
        for (int k = j + 1; k < n - 1; k++) {
          if (w[k] > 1000000 / w[i] / w[j]) {
            continue;
          }
          int v = w[i] * w[j] * w[k];
          res += cnt[k + 1][v];
        }
      }
    }
    return res;
  }
};