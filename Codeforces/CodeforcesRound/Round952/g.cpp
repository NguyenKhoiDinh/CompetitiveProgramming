#include <iostream>
#include <vector> 
int numTest;
const long long mod = 1000000007LL; 
struct matrix {
  int row, col;
  std::vector <std::vector <long long> > data; 
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
matrix fastpow(const matrix &M, const long long &n) {
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
long long fastpowInt(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL;
  }
  long long ret = fastpowInt(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int l, r, k;
    std::cin >> l >> r >> k;
    if (k >= 10) {
      std::cout << 0 << std::endl;
      continue; 
    }        
    if (k == 1) {
      long long ret = fastpowInt(10LL, r);
      ret--; 
      (ret += mod) %= mod; 
      ret -= fastpowInt(10LL, l);
      ret++; 
      (ret += mod) %= mod;
      std::cout << ret << std::endl;
      continue;  
    }
    int numb = 0; 
    for (int dig = 0; dig <= 9; dig++) {
      if (k * dig < 10) {
        numb++;
      }
    }
    matrix F(1, numb + 1);
    for (int i = 1; i < numb; i++) {
      F.data[0][i] = 1; 
      F.data[0][numb]++; 
    }
    matrix base(numb + 1, numb + 1);
    base.data[numb][numb] = 1;
    for (int i = 0; i < numb; i++) {
      base.data[i][numb] = numb;
      for (int j = 0; j < numb; j++) {
        base.data[j][i] = 1; 
      }
    }
    matrix ans1 = (r == 1 ? F : F * fastpow(base, r - 1));
    if (l > 0) {
      matrix ans2 = (l == 1 ? F : F * fastpow(base, l - 1)); 
      ans1.data[0][numb] -= ans2.data[0][numb];
      (ans1.data[0][numb] += mod) %= mod;  
    }
    std::cout << ans1.data[0][numb] << std::endl;  
  }
  return 0; 
}