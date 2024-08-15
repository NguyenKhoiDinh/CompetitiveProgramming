#include <iostream>
#include <vector> 
const long long mod = 1000000007LL; 
long long f[5]; 
struct matrix {
  std::vector <std::vector <long long> > data;
  int row, col;
  matrix(int _row, int _col) {
    row = _row;
    col = _col;
    data.resize(row);
    for (int i = 0; i < row; i++) {
      data[i].resize(col, 0); 
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
matrix fastpow(const matrix &M, const long long n) {
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
  long long n; 
  std::cin >> n; 
  f[0] = 1LL; 
  long long r = n % 10; 
  n /= 10; 
  for (int i = 1; i <= 4; i++) {
    for (int j = 0; j < i; j++) {
      f[i] += f[j] * (5 - (i - j)) * (5 - (i - j)); 
    }
  }
  if (n <= 4) {
    long long ans = 0LL; 
    for (int i = 0; i <= n; i++) {
      ans += f[i];
      ans %= mod; 
    }
    if (n == 4 && r >= 5) {
      ans--;
      ans += mod;
      ans %= mod;       
    }
    std::cout << ans;
    return 0; 
  }
  n -= 4; 
  matrix ansF(1, 5);
  ansF.data = { {f[0], f[1], f[2], f[3], f[4]} };
  matrix base(5, 5);
  base.data = { {0, 0, 0, 0, 0}, 
                {1, 0, 0, 0, 1}, 
                {0, 1, 0, 0, 4}, 
                {0, 0, 1, 0, 9}, 
                {0, 0, 0, 1, 16}
              };
  base = fastpow(base, n);
  ansF = ansF * base; 
  long long ans = 0LL;
  for (int i = 0; i <= 4; i++) {
    (ans += ansF.data[0][i]) %= mod; 
  }   
  if (r >= 5) {
    ans -= ansF.data[0][0];
    ans += mod; 
    ans %= mod; 
  }
  std::cout << ans; 
  return 0; 
}