#include <iostream> 
#include <vector>

const long long mod = 1000000007LL; 
int n, k; 
struct matrix {
  int row, col; 
  std::vector <std::vector <long long> > data; 
  matrix(int _row, int _col) {
    row = _row; 
    col = _col; 
    data.resize(row);
    for (int i = 0; i < row; i++) {
      data[i].resize(col, 0LL); 
    }
  }
  matrix operator * (const matrix &other) {
    matrix ret(row, other.col); 
    for (int i = 0; i < ret.row; i++) {
      for (int j = 0; j < ret.col; j++) {
        for (int k = 0; k < col; k++) {
          (ret.data[i][j] += (data[i][k] * other.data[k][j]) % mod) %= mod; 
        }
      }
    }
    return ret; 
  }
};

matrix fastpow(const matrix &M, int n) {
  if (n == 1) {
    return M; 
  }
  matrix ret = fastpow(M, n / 2);
  ret = ret * ret; 
  if (n % 2 == 1) {
    ret = ret * M; 
  }
  return ret; 
}

int main () {
  std::cin >> n >> k; 
  matrix ret(1, k); 
  ret.data[0][0] = 1; 
  matrix base(k, k);
  for (int i = 0; i < k; i++) {
    int previ = (i - 1 + k) % k; 
    base.data[previ][i] = 3LL; 
    previ = (i - 2 % k + k) % k; 
    base.data[previ][i] = 3LL; 
    base.data[i][i] = 1LL; 
  }
  base = fastpow(base, n); 
  ret = ret * base; 
  std::cout << (ret.data[0][0] - 1 + mod) % mod; 
  return 0; 
}