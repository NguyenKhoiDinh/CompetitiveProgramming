#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005; 
const long long inf = 100000000000007LL;
int numTest;
long long X[MAX_N], Y[MAX_N];
long long K[MAX_N];
long long sumRight[MAX_N], sumLeft[MAX_N];
int n;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> X[i] >> Y[i]; 
    }
    sort(X, X + n);
    for (int i = 0; i < n; i++) {
      K[i] = X[i] - i; 
    }
    sort(Y, Y + n); 
    sort(K, K + n);
    sumRight[n - 1] = Y[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      sumRight[i] = sumRight[i + 1] + Y[i];
    }
    sumLeft[0] = Y[0];
    for (int i = 1; i < n; i++) {
      sumLeft[i] = sumLeft[i - 1] + Y[i];
    }
    long long valueY = inf;
    for (int i = 0; i < n; i++) {
      long long value = 0LL; 
      if (i > 0) {
        value += 1LL * i * Y[i] - sumLeft[i - 1];
      }
      if (i < n - 1) {
        value += sumRight[i + 1] - 1LL * (n - 1 - i) * Y[i];
      }
      valueY = min(valueY, value);
    }
    sumRight[n - 1] = K[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      sumRight[i] = sumRight[i + 1] + K[i];
    }
    sumLeft[0] = K[0];
    for (int i = 1; i < n; i++) {
      sumLeft[i] = sumLeft[i - 1] + K[i];
    }
    long long valueK = inf;
    for (int i = 0; i < n; i++) {
      long long value = 0LL; 
      if (i > 0) {
        value += 1LL * i * K[i] - sumLeft[i - 1];
      }
      if (i < n - 1) {
        value += sumRight[i + 1] - 1LL * (n - 1 - i) * K[i];
      }
      valueK = min(valueK, value);
    }
    cout << valueK + valueY << endl;
  }
  return 0;
}