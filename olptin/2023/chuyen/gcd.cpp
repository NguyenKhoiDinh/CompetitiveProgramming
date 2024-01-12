#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
long long a, b, M; 
long long mul(const long long &a, const long long &b) {
  if (b <= 1000000) {
    return (a * b) % M; 
  }
  long long d = b / 1000000;
  long long r = b % 1000000; 
  long long ret = mul(a, d);
  (ret *= 1000000) %= M; 
  (ret += (a * r) % M) %= M;
  return ret; 
}
struct matrix {
  int row, col; 
  std::vector <std::vector <long long> > data; 
  matrix(const int _row, const int _col) {
    row = _row;
    col = _col; 
    data.resize(row);
    for (int i = 0; i < row; i++) {
      data[i].resize(col, 0LL); 
    }
  }
  matrix operator *(const matrix &other) {
    matrix ret(row, other.col); 
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < other.col; j++) {
        for (int k = 0; k < col; k++) {
          (ret.data[i][j] += mul(data[i][k], other.data[k][j])) %= M; 
        }
      }
    }
    return ret; 
  }
};

matrix fastpow(const matrix &A, const long long &n) {
  if (n == 1) {
    return A; 
  }
  matrix ret = fastpow(A, n / 2); 
  ret = ret * ret; 
  if (n % 2 == 1) {
    ret = ret * A; 
  }
  return ret; 
}

int main () {
  std::cin >> a >> b >> M; 
  long long n = std::__gcd(a, b); 
  if (n <= 1) {
    std::cout << n % M;
    return 0; 
  }
  matrix ans(1, 2); 
  ans.data[0][0] = 0;
  ans.data[0][1] = 1; 
  matrix base(2, 2); 
  base.data[0][1] = 1;
  base.data[1][0] = 1;
  base.data[1][1] = 1;
  ans = ans * fastpow(base, n - 1); 
  std::cout << ans.data[0][1]; 
  return 0; 
}