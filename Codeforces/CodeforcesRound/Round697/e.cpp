#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 1005;
const int MOD = 1000000007;
int numTest;
int cnt[MAX_N], a[MAX_N];
int n, k;
int C[MAX_N][MAX_N];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  for (int i = 0; i < MAX_N; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
  }
  for (int i = 1; i < MAX_N; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i < MAX_N; i++) {
      cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    for (int i = n; i >= 1; i--) {
      if (k > cnt[i]) {
        k -= cnt[i];
      }
      else {
        cout << C[cnt[i]][k] << endl;
        break;
      }
    }
  }
  return 0;
}