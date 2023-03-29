#include <iostream>
#include <vector> 
const long long mod = 1000000007;
struct matrix {
  int row, col; 
  std::vector <std::vector <long long> > data; 
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

matrix fastpow(const matrix &M, const long long &n) {
  if (n == 1) {
    return M; 
  }
  else {              
    matrix ret = fastpow(M, n >> 1);
    ret = ret * ret; 
    if (n % 2 == 1) {
      ret = ret * M; 
    }
    return ret; 
  }
}

int main () {
  std::cin >> n >> k; 
  matrix base(n, 1); 
  matrix ret(n, n); 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> ret.data[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    base.data[i][0] = 1; 
  }
  matrix ans = fastpow(ret, k); 
  ans = ans * base; 
  long long res = 0LL;
  for (int i = 0; i < n; i++) {
    (res += ans.data[i][0]) %= mod; 
  }
  std::cout << res; 
  return 0;
}