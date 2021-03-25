#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 53;
const long long inf = 1000000000000000LL;
struct Matrix {
  int N;
  long long M[MAX_N][MAX_N];
  Matrix operator * (const Matrix &hs) const {
    Matrix res;
    res.N = N;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        res.M[i][j] = inf;
        for (int k = 1; k <= N; k++) {
          res.M[i][j] = min(res.M[i][j], M[i][k] + hs.M[k][j]);
        }
      }
    }
    return res;
  }
};
int cost[MAX_N][MAX_N];
long long dist[MAX_N][MAX_N];
Matrix baseMatrix;

Matrix POW(Matrix &M, long long N) {
  if (N == 1) {
    return M;
  }
  Matrix tmp = POW(M, N >> 1);
  tmp = tmp * tmp;
  if (N % 2 == 1) {
    tmp = tmp * M;
  }
  return tmp;
}

class AtLeastKDays {
  public:
  long long sumOfMinCosts(vector <string> costs, int minDays) {
    int N = (int) costs.size();
    baseMatrix.N = N;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j) {
          dist[i][j] = inf;
          baseMatrix.M[i][j] = inf;
        }
        else {
          dist[i][j] = costs[i - 1][j - 1] - '0';
          baseMatrix.M[i][j] = dist[i][j];
        }
      }
    }
    for (int k = 1; k <= N; k++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    Matrix res = POW(baseMatrix, minDays);
    long long sum = 0LL;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        long long val = res.M[i][j];
        for (int k = 1; k <= N; k++) {
          val = min(val, res.M[i][k] + dist[k][j]);
        }
        sum += val;
      }
    }
    return sum;
  }
};

AtLeastKDays A;

int main () {
  cout << A.sumOfMinCosts({"-111111111", "1-11111111", "11-1111111", "111-111111", "1111-11111", "11111-1111", "111111-111", "1111111-11", "11111111-1", "111111111-"},
1000000000);
  return 0;
}