#include <bits/stdc++.h>

using namespace std;

bool check[2000005];

int main () {
  int lim = 2000000;
  for (int i = 1; i <= lim; i++) {
    check[i] = true;
  }
  check[1] = false;
  for (int i = 2; i * i <= lim; i++) {
    for (int j = i * i; j <= lim; j += i) {
      check[j] = false;
    }
  }
  long long ans = 0;
  for (int i = 2; i <= lim; i++) {
    if (check[i] == true) {
      ans += i;
    }
  }
  cout << ans;
  return 0;
}


/*
a + b + c = 1000
a^2 + b^2 = c^2

a^2 + b^2 + c^2 + 2ab + 2bc + 2ca = 1000000
2c^2 + 2ab + 2bc + 2ca = 1000000
*/