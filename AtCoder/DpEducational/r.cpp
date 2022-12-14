#include <bits/stdc++.h>

using namespace std;
const long long mod = 1000000007;
struct matrix {
  int row, col; 
  vector <vector <long long> > data; 
  matrix(int _row, int _col) {
    row = _row;
    col = _col; 
    data.resize(row); 
    for (int i = 0; i < row; i++) {
      data[i].resize(col); 
      for (int j = 0; j < col; j++) {
        data[i][j] = 0; 
      }
    }
  } 
  matrix operator * (const matrix &other) {
    matrix ret(row, other.col); 
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < other.col; j++) {
        for (int k = 0; k < col; k++) {
          (ret.data[i][j] += (data[i][k] * other.data[k][j]) % mod) %= mod; 
        }
      }
    }
    return ret; 
  }
};
int n;
long long k; 

matrix POW(const matrix &M, long long N) {
  if (N == 1) {
    return M; 
  }
  else {              
    matrix tmp = POW(M, N >> 1);
    tmp = tmp * tmp; 
    if (N % 2 == 1) {
      tmp = tmp * M; 
    }
    return tmp; 
  }
}

int main () {
  cin >> n >> k; 
  matrix base(n, 1); 
  matrix M(n, n); 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M.data[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    base.data[i][0] = 1; 
  }
  matrix ans = POW(M, k); 
  ans = ans * base; 
  long long res = 0LL;
  for (int i = 0; i < n; i++) {
    (res += ans.data[i][0]) %= mod; 
  }
  cout << res; 
  return 0;
}