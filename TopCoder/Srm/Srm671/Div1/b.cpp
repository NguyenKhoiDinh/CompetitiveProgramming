#include <bits/stdc++.h>

using namespace std;
map <pair <int, int>, int> countFraction;

class BearDarts {
  public:
  long long count(vector <int> w) {
    long long ans = 0;
    int n = (int) w.size();
    for (int i = n - 2; i >= 1; i--) {
      for (int j = 0; j < i; j++) {
        int deno = w[j];
        int nume = w[i];
        int gcd = __gcd(deno, nume);
        deno /= gcd;
        nume /= gcd;
        ans += countFraction[make_pair(deno, nume)];
      }
      for (int j = i + 1; j < n; j++) {
        int deno = w[j];
        int nume = w[i];
        int gcd = __gcd(deno, nume);
        deno /= gcd;
        nume /= gcd;
        countFraction[make_pair(deno, nume)]++;
      }
    }
    return ans;
  }
};

int main () {
  return 0;
}