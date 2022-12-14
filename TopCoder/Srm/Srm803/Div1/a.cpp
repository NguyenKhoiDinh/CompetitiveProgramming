#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 605;
long long adj[MAX_N][MAX_N];
long long ways[MAX_N][MAX_N];

class MarriageAndCirclingChallenge {
  public:
  long long solve(int N, int threshold, int state) {
    long long sta = state;
    long long value = (1LL << 31);
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        sta = (sta * 1103515245LL + 12345LL) % value;
        long long ret = sta % 100;
        if (ret < threshold) {
          adj[i][j] = 1;
        }
        else {
          adj[j][i] = 1;
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i != j) {
          for (int k = 0; k < N; k++) {
            if (adj[i][k] == 1 && adj[k][j] == 1) {
              ways[i][j]++;
            }
          }
        }
      }
    }
    long long ans = 0LL;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        ans += 1LL * ways[i][j] * ways[j][i];
      }
    }
    return ans / 2;
  }
};
MarriageAndCirclingChallenge M;

int main () {
  cout << M.solve(9,
20,
1234567);
  return 0;
}