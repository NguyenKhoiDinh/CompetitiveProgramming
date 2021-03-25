#include <bits/stdc++.h>

using namespace std;

class NRooksPosition {
  public:
  long long minSteps(int N, vector <int> Xprefix, vector <int> Yprefix, int A, int B, int C) {
    vector <long long> X, Y;
    X.resize(N, 0);
    Y.resize(N, 0);
    int sz = (int) Xprefix.size();
    for (int i = 0; i < N; i++) {
      if (i < sz) {
        X[i] = Xprefix[i];
        Y[i] = Yprefix[i];
      }
      else {
        X[i] = (1LL * X[i - 1] * A + 1LL * X[i - 2] * B) % C;
        Y[i] = (1LL * Y[i - 1] * A + 1LL * Y[i - 2] * B) % C;
      }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = 0; i < N; i++) {
      X[i] -= i;
      Y[i] -= i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    long long valX = X[N / 2], valY = Y[N / 2];
    long long res = 0LL;
    for (int i = 0; i < N; i++) {
      res += abs(valX - X[i]) + abs(valY - Y[i]);
    }
    return res;
  }
};

int main () {
  return 0;
}